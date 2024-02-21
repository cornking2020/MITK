# The entries in the mitk_modules list must be
# ordered according to their dependencies.

set(MITK_MODULES
  Log
  Core
  CommandLine
  CoreCmdApps
  AppUtil
  LegacyIO
  DataTypesExt
  Annotation
  LegacyGL
  AlgorithmsExt
  MapperExt
  DICOM
  DICOMQI
  DICOMTesting
  SceneSerializationBase
  PlanarFigure
  ImageDenoising
  ImageExtraction
  SceneSerialization
  Gizmo
  GraphAlgorithms
  Multilabel
  Chart
  ImageStatistics
  ContourModel
  SurfaceInterpolation
  Segmentation
  QtWidgets
  QtWidgetsExt
  ImageStatisticsUI
  SegmentationUI
  MatchPointRegistration
  MatchPointRegistrationUI
  Classification
  OpenIGTLink
  IGTBase
  IGT
  CameraCalibration
  OpenCVVideoSupport
  QtOverlays
  ToFHardware
  ToFProcessing
  ToFUI
  US
  USUI
  DICOMUI
  Remeshing
  Python
  QtPython
  Persistence
  OpenIGTLinkUI
  IGTUI
  RT
  RTUI
  IOExt
  XNAT
  TubeGraph
  BoundingShape
  RenderWindowManagerUI
  SemanticRelations
  SemanticRelationsUI
  CEST
  BasicImageProcessing
  ModelFit
  ModelFitUI
  Pharmacokinetics
  PharmacokineticsUI
  DICOMPM
  REST
  RESTService
  DICOMweb
  ROI
)
