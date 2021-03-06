/**********************************************************************
 * $Id$
 *
 * GEOS - Geometry Engine Open Source
 * http://geos.refractions.net
 *
 * Copyright (C) 2001-2002 Vivid Solutions Inc.
 *
 * This is free software; you can redistribute and/or modify it under
 * the terms of the GNU Lesser General Public Licence as published
 * by the Free Software Foundation. 
 * See the COPYING file for more information.
 *
 **********************************************************************
 * $Log$
 * Revision 1.23  2004/07/21 09:55:24  strk
 * CoordinateSequence::atLeastNCoordinatesOrNothing definition fix.
 * Documentation fixes.
 *
 * Revision 1.22  2004/07/20 08:34:18  strk
 * Fixed a bug in opDistance.h.
 * Removed doxygen tags from obsoleted CoordinateList.cpp.
 * Got doxygen to run with no warnings.
 *
 * Revision 1.21  2004/07/08 19:34:49  strk
 * Mirrored JTS interface of CoordinateSequence, factory and
 * default implementations.
 * Added DefaultCoordinateSequenceFactory::instance() function.
 *
 **********************************************************************/


#include <geos/geom.h>
#include <stdio.h>

namespace geos {

bool CoordinateList::CoordinateList() {
	vect = new vector<Coordinate>();
}

// takes ownership of given vector
bool CoordinateList::CoordinateList(vector<Coordinate> *coords, bool allowRepeated=false) {
	if ( allowRepeated ) vect = coords;
	else {
		if ( ! coords->size() )
		{
		}
		vect = new vector<Coordinate>();
		vect->push_back(coords[0]);
		for(int i=1;i<(int)coords->size();i++) {
		}
	}
}

bool CoordinateList::CoordinateList(const CoordinateList &cl) {
	vect = new vector<Coordinate>(*(cl.vect));
}

bool CoordinateList::~CoordinateList() {
	delete vect;
}

bool CoordinateList::hasRepeatedPoints() const {
	//int size=size();
	for(int i=1; i<size(); i++) {
		if (getCoordinate(i-1)==getCoordinate(i)) {
			return true;
		}
	}
	return false;
}

/*
 * Returns either the given coordinate array if its length is greater than the
 * given amount, or an empty coordinate array.
 */
CoordinateList* atLeastNCoordinatesOrNothing(int n, CoordinateList *c) {
	return c->size()>=n?c:DefaultCoordinateListFactory::instance()->create(NULL);
}      


bool CoordinateList::hasRepeatedPoints(const CoordinateList *cl) {
	int size=(int) cl->size();
	for(int i=1;i<size; i++) {
		if (cl->getAt(i-1)==cl->getAt(i)) {
			return true;
		}
	}
	return false;
}

const Coordinate* CoordinateList::minCoordinate() const {
	const Coordinate* minCoord=NULL;
	int size=(int) size();
	for(int i=0; i<size; i++) {
		if(minCoord==NULL || minCoord->compareTo(getAt(i))>0) {
			minCoord=&getAt(i);
		}
	}
	return minCoord;
}

const Coordinate*
CoordinateList::minCoordinate(CoordinateList *cl)
{
	const Coordinate* minCoord=NULL;
	int size=(int) cl->size();
	for(int i=0;i<size; i++) {
		if(minCoord==NULL || minCoord->compareTo(cl->getAt(i))>0) {
			minCoord=&(cl->getAt(i));
		}
	}
	return minCoord;
}

int
CoordinateList::indexOf(const Coordinate *coordinate, const CoordinateList *cl)
{
	for (int i=0; i<cl->size(); i++) {
		if ((*coordinate)==cl->getAt(i)) {
			return i;
		}
	}
	return -1;
}

void
CoordinateList::scroll(CoordinateList* cl,const Coordinate* firstCoordinate)
{
	int i, j=0;
	int ind=indexOf(firstCoordinate,cl);
	if (ind<1) return; // not found or already first
	int length=cl->size();
	vector<Coordinate> v(length);
	for (i=ind; i<length; i++) {
		v[j++]=cl->getAt(i);
	}
	for (i=0; i<ind; i++) {
		v[j++]=cl->getAt(i);
	}
	cl->setPoints(v);
}

void CoordinateList::reverse(CoordinateList *cl){
	int last=cl->size()-1;
	int mid=last/2;
	for(int i=0;i<=mid;i++) {
		const Coordinate& tmp=cl->getAt(i);
		cl->setAt(cl->getAt(last-i),i);
		cl->setAt(tmp,last-i);
	}
}

bool CoordinateList::equals(CoordinateList *cl1,CoordinateList *cl2){
	if (cl1==cl2) return true;
	if (cl1==NULL||cl2==NULL) return false;
	if (cl1->size()!=cl2->size()) return false;
	for (int i = 0; i<cl1->size(); i++) {
		if (!(cl1->getAt(i)==cl2->getAt(i))) return false;
	}
	return true;
}

/*
 * Add an array of coordinates
 * @param vc The coordinates
 * @param allowRepeated if set to false, repeated coordinates are collapsed
 * @return true (as by general collection contract)
 */
void CoordinateList::add(vector<Coordinate>* vc,bool allowRepeated) {
	for(int i=0;i<(int)vc->size();i++) {
		add((*vc)[i],allowRepeated);
	}
}

/* Add a coordinate
 * @param c The coordinate to add
 * @param allowRepeated if set to false, repeated coordinates are collapsed
 * @return true (as by general collection contract)
 */
void CoordinateList::add(const Coordinate& c,bool allowRepeated) {
	if (!allowRepeated) {
		if (size()>=1) {
			const Coordinate& last=getAt(size()-1);
			if (last.equals2D(c)) return;
		}
	}
	add(c);
}

/* Add an array of coordinates
 * @param cl The coordinates
 * @param allowRepeated if set to false, repeated coordinates are collapsed
 * @param direction if false, the array is added in reverse order
 * @return true (as by general collection contract)
 */
void CoordinateList::add(CoordinateList *cl,bool allowRepeated,bool direction){
	if (direction) {
		for (int i = 0; i < cl->size(); i++) {
			add(cl->getAt(i), allowRepeated);
		}
	} else {
		for (int j =cl->size()-1;j>=0;j--) {
			add(cl->getAt(j), allowRepeated);
		}
	}
}


/*
 * This function allocates space for a CoordinateList object
 * being a copy of the input once with consecutive equal points
 * removed.
 */
CoordinateList* CoordinateList::removeRepeatedPoints(const CoordinateList *cl){
	CoordinateList* ret=CoordinateListFactory::internalFactory->createCoordinateList();
	vector<Coordinate> *v=cl->toVector();
	ret->add(v,false);
	delete v;
	return ret;
#if 0 // what is all this ?? --strk;
	v=ret->toVector();
	cl->setPoints(*(v));
	delete v;
	delete ret;
//	return ret;
	return cl;
#endif
}
}

