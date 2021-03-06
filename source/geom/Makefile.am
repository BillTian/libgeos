prefix=@prefix@
top_srcdir=@top_srcdir@
GEOS_VERSION=@VERSION@

lib_LTLIBRARIES = libgeos.la

INCLUDES = -I$(top_srcdir)/source/headers -DGEOS_VERSION=""$(GEOS_VERSION)""

DIR_SOURCES = \
	Coordinate.cpp \
	CoordinateSequence.cpp \
	CoordinateSequenceFactory.cpp \
	DefaultCoordinateSequence.cpp \
	DefaultCoordinateSequenceFactory.cpp \
	PointCoordinateSequenceFactory.cpp \
	PointCoordinateSequence.cpp \
	Dimension.cpp \
	Envelope.cpp \
	Geometry.cpp \
	GeometryCollection.cpp \
	GeometryCollectionIterator.cpp \
	GeometryComponentFilter.cpp \
	GeometryFactory.cpp \
	IntersectionMatrix.cpp \
	LinearRing.cpp \
	LineSegment.cpp \
	LineString.cpp \
	Location.cpp \
	MultiLineString.cpp \
	MultiPoint.cpp \
	MultiPolygon.cpp \
	Point.cpp \
	Polygon.cpp \
	PrecisionModel.cpp \
	TopologyException.cpp \
	Triangle.cpp

EXTERNAL_SOURCES =  \
	util/GeometryEditor.cpp \
	util/LinearComponentExtracter.cpp \
	util/PointExtracter.cpp \
	util/PolygonExtracter.cpp \
	../algorithm/CGAlgorithms.cpp \
	../algorithm/CentroidArea.cpp \
	../algorithm/CentroidLine.cpp \
	../algorithm/CentroidPoint.cpp \
	../algorithm/ConvexHull.cpp \
	../algorithm/HCoordinate.cpp \
	../algorithm/InteriorPointArea.cpp \
	../algorithm/InteriorPointLine.cpp \
	../algorithm/InteriorPointPoint.cpp \
	../algorithm/LineIntersector.cpp \
	../algorithm/MCPointInRing.cpp \
	../algorithm/MinimumDiameter.cpp \
	../algorithm/NonRobustCGAlgorithms.cpp \
	../algorithm/NonRobustLineIntersector.cpp \
	../algorithm/NotRepresentableException.cpp \
	../algorithm/PointLocator.cpp \
	../algorithm/RobustCGAlgorithms.cpp \
	../algorithm/RobustDeterminant.cpp \
	../algorithm/RobustLineIntersector.cpp \
	../algorithm/SIRtreePointInRing.cpp \
	../algorithm/SimplePointInAreaLocator.cpp \
	../algorithm/SimplePointInRing.cpp \
	../precision/CommonBits.cpp \
	../precision/CommonBitsOp.cpp \
	../precision/CommonBitsRemover.cpp \
	../precision/EnhancedPrecisionOp.cpp \
	../precision/SimpleGeometryPrecisionReducer.cpp \
	../geomgraph/Depth.cpp \
	../geomgraph/DirectedEdge.cpp \
	../geomgraph/DirectedEdgeStar.cpp \
	../geomgraph/Edge.cpp \
	../geomgraph/EdgeEnd.cpp \
	../geomgraph/EdgeEndStar.cpp \
	../geomgraph/EdgeIntersection.cpp \
	../geomgraph/EdgeIntersectionList.cpp \
	../geomgraph/EdgeNodingValidator.cpp \
	../geomgraph/EdgeList.cpp \
	../geomgraph/EdgeRing.cpp \
	../geomgraph/GeometryGraph.cpp \
	../geomgraph/GraphComponent.cpp \
	../geomgraph/Label.cpp \
	../geomgraph/Node.cpp \
	../geomgraph/NodeFactory.cpp \
	../geomgraph/NodeMap.cpp \
	../geomgraph/PlanarGraph.cpp \
	../geomgraph/Position.cpp \
	../geomgraph/Quadrant.cpp \
	../geomgraph/TopologyLocation.cpp \
	../geomgraph/index/MonotoneChain.cpp \
	../geomgraph/index/MonotoneChainEdge.cpp \
	../geomgraph/index/MonotoneChainIndexer.cpp \
	../geomgraph/index/SegmentIntersector.cpp \
	../geomgraph/index/SimpleEdgeSetIntersector.cpp \
	../geomgraph/index/SimpleMCSweepLineIntersector.cpp \
	../geomgraph/index/SimpleSweepLineIntersector.cpp \
	../geomgraph/index/SweepLineEvent.cpp \
	../geomgraph/index/SweepLineSegment.cpp \
	../index/bintree/Bintree.cpp \
	../index/bintree/BinTreeInterval.cpp \
	../index/bintree/BinTreeNode.cpp \
	../index/bintree/Key.cpp \
	../index/bintree/NodeBase.cpp \
	../index/bintree/Root.cpp \
	../index/chain/indexMonotoneChain.cpp \
	../index/chain/MonotoneChainBuilder.cpp \
	../index/chain/MonotoneChainOverlapAction.cpp \
	../index/chain/MonotoneChainSelectAction.cpp \
	../index/quadtree/DoubleBits.cpp \
	../index/quadtree/IntervalSize.cpp \
	../index/quadtree/Quadtree.cpp \
	../index/quadtree/QuadTreeKey.cpp \
	../index/quadtree/QuadTreeNode.cpp \
	../index/quadtree/QuadTreeNodeBase.cpp \
	../index/quadtree/QuadTreeRoot.cpp \
	../index/strtree/AbstractNode.cpp \
	../index/strtree/AbstractSTRtree.cpp \
	../index/strtree/Interval.cpp \
	../index/strtree/ItemBoundable.cpp \
	../index/strtree/SIRtree.cpp \
	../index/strtree/STRtree.cpp \
	../index/sweepline/indexSweepLineEvent.cpp \
	../index/sweepline/SweepLineIndex.cpp \
	../index/sweepline/SweepLineInterval.cpp \
	../io/ParseException.cpp \
	../io/StringTokenizer.cpp \
	../io/WKTReader.cpp \
	../io/WKTWriter.cpp \
	../io/Writer.cpp \
	../io/Unload.cpp \
	../operation/GeometryGraphOperation.cpp \
	../operation/IsSimpleOp.cpp \
	../operation/buffer/BufferBuilder.cpp \
	../operation/buffer/BufferOp.cpp \
	../operation/buffer/BufferSubgraph.cpp \
	../operation/buffer/OffsetCurveBuilder.cpp \
	../operation/buffer/OffsetCurveSetBuilder.cpp \
	../operation/buffer/RightmostEdgeFinder.cpp \
	../operation/buffer/SubgraphDepthLocater.cpp \
	../operation/distance/ConnectedElementLocationFilter.cpp \
	../operation/distance/ConnectedElementPointFilter.cpp \
	../operation/distance/DistanceOp.cpp \
	../operation/distance/GeometryLocation.cpp \
	../operation/overlay/EdgeSetNoder.cpp \
	../operation/overlay/LineBuilder.cpp \
	../operation/overlay/MaximalEdgeRing.cpp \
	../operation/overlay/MinimalEdgeRing.cpp \
	../operation/overlay/OverlayNodeFactory.cpp \
	../operation/overlay/OverlayOp.cpp \
	../operation/overlay/PointBuilder.cpp \
	../operation/overlay/PolygonBuilder.cpp \
	../operation/overlay/ElevationMatrix.cpp \
	../operation/overlay/ElevationMatrixCell.cpp \
	../operation/overlay/ElevationMatrixFilter.cpp \
	../operation/relate/EdgeEndBuilder.cpp \
	../operation/relate/EdgeEndBundle.cpp \
	../operation/relate/EdgeEndBundleStar.cpp \
	../operation/relate/RelateComputer.cpp \
	../operation/relate/RelateNode.cpp \
	../operation/relate/RelateNodeFactory.cpp \
	../operation/relate/RelateNodeGraph.cpp \
	../operation/relate/RelateOp.cpp \
	../operation/valid/ConnectedInteriorTester.cpp \
	../operation/valid/ConsistentAreaTester.cpp \
	../operation/valid/IsValidOp.cpp \
	../operation/valid/QuadtreeNestedRingTester.cpp \
	../operation/valid/RepeatedPointTester.cpp \
	../operation/valid/SimpleNestedRingTester.cpp \
	../operation/valid/SweeplineNestedRingTester.cpp \
	../operation/valid/TopologyValidationError.cpp \
	../operation/linemerge/EdgeString.cpp \
	../operation/linemerge/LineMergeDirectedEdge.cpp \
	../operation/linemerge/LineMergeEdge.cpp \
	../operation/linemerge/LineMergeGraph.cpp \
	../operation/linemerge/LineMerger.cpp \
	../operation/polygonize/PolygonizeDirectedEdge.cpp \
	../operation/polygonize/PolygonizeEdge.cpp \
	../operation/polygonize/PolygonizeGraph.cpp \
	../operation/polygonize/Polygonizer.cpp \
	../operation/polygonize/polygonizeEdgeRing.cpp \
	../planargraph/planarDirectedEdge.cpp \
	../planargraph/planarDirectedEdgeStar.cpp \
	../planargraph/planarEdge.cpp \
	../planargraph/planarGraphComponent.cpp \
	../planargraph/planarNode.cpp \
	../planargraph/planarNodeMap.cpp \
	../planargraph/planarPlanarGraph.cpp \
	../noding/IteratedNoder.cpp \
	../noding/MCQuadtreeNoder.cpp \
	../noding/Noder.cpp \
	../noding/NodingValidator.cpp \
	../noding/SegmentNode.cpp \
	../noding/SegmentNodeList.cpp \
	../noding/SegmentString.cpp \
	../noding/SimpleNoder.cpp \
	../noding/nodingSegmentIntersector.cpp \
	../noding/snapround/SegmentSnapper.cpp \
	../noding/snapround/SimpleSegmentStringsSnapper.cpp \
	../noding/snapround/SnapRounder.cpp \
	../util/Assert.cpp \
	../util/AssertionFailedException.cpp \
	../util/CoordinateArrayFiter.cpp \
	../util/GEOSException.cpp \
	../util/IllegalArgumentException.cpp \
	../util/UniqueCoordinateArrayFilter.cpp \
	../util/UnsupportedOperationException.cpp \
	../util/GeometricShapeFactory.cpp \
	../util/Profiler.cpp 

libgeos_la_SOURCES = $(DIR_SOURCES) $(EXTERNAL_SOURCES)

libgeos_la_LDFLAGS = -version-info @INTERFACE_CURRENT@:@INTERFACE_REVISION@:@INTERFACE_AGE@

dist-local:
	cp -p $(DIR_SOURCES) Makefile.am Makefile.in $(distdir)

