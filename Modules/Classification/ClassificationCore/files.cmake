file(GLOB_RECURSE H_FILES RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}/include/*")

set(CPP_FILES
  mitkConfigurationHolder.cpp
  mitkAbstractClassifier.cpp

  Algorithms/itkLabelSampler.cpp

  Transformer/mitkEigenToImageTransform.cpp
  Transformer/mitkImageToEigenTransform.cpp

  Features/itkNeighborhoodFunctorImageFilter.cpp
)

set( TOOL_FILES
)
