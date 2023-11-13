/*============================================================================

The Medical Imaging Interaction Toolkit (MITK)

Copyright (c) German Cancer Research Center (DKFZ)
All rights reserved.

Use of this source code is governed by a 3-clause BSD license that can be
found in the LICENSE file.

============================================================================*/

#ifndef mitkTwoStepLinearModel_h
#define mitkTwoStepLinearModel_h

#include "mitkModelBase.h"

#include "MitkModelFitExports.h"

namespace mitk
{

  class MITKMODELFIT_EXPORT TwoStepLinearModel : public mitk::ModelBase
  {

  public:
    typedef TwoStepLinearModel Self;
    typedef mitk::ModelBase Superclass;
    typedef itk::SmartPointer< Self >                            Pointer;
    typedef itk::SmartPointer< const Self >                      ConstPointer;

    typedef Superclass::ParameterNameType  ParameterNameType;
    typedef Superclass::ParametersSizeType ParametersSizeType;

    /** Method for creation through the object factory. */
    itkFactorylessNewMacro(Self);
    itkCloneMacro(Self);

    /** Run-time type information (and related methods). */
    itkTypeMacro(TwoStepLinearModel, ModelBase)

    static const std::string NAME_PARAMETER_y0;
    static const std::string NAME_PARAMETER_x0;
    static const std::string NAME_PARAMETER_b0;
    static const std::string NAME_PARAMETER_b1;

    static const unsigned int NUMBER_OF_PARAMETERS;

    static const std::string UNIT_PARAMETER_y0;
    static const std::string UNIT_PARAMETER_x0;
    static const std::string UNIT_PARAMETER_b0;
    static const std::string UNIT_PARAMETER_b1;

    static const unsigned int POSITION_PARAMETER_y0;
    static const unsigned int POSITION_PARAMETER_x0;
    static const unsigned int POSITION_PARAMETER_b0;
    static const unsigned int POSITION_PARAMETER_b1;

    static const std::string NAME_DERIVED_PARAMETER_auc;
    static const std::string NAME_DERIVED_PARAMETER_y_fin;
    static const std::string NAME_DERIVED_PARAMETER_y_max;
    static const std::string NAME_DERIVED_PARAMETER_y1;

    static const unsigned int NUMBER_OF_DERIVED_PARAMETERS;

    static const std::string UNIT_DERIVED_PARAMETER_auc;
    static const std::string UNIT_DERIVED_PARAMETER_y_fin;
    static const std::string UNIT_DERIVED_PARAMETER_y_max;
    static const std::string UNIT_DERIVED_PARAMETER_y1;

    static const unsigned int NUMBER_OF_STATIC_PARAMETERS;

    static const std::string MODEL_DISPLAY_NAME;

    static const std::string MODEL_TYPE;

    static const std::string FUNCTION_STRING;

    static const std::string X_NAME;

    static const std::string X_AXIS_NAME;

    static const std::string X_AXIS_UNIT;

    static const std::string Y_AXIS_NAME;

    static const std::string Y_AXIS_UNIT;


    ParameterNamesType GetParameterNames() const override;

    ParametersSizeType  GetNumberOfParameters() const override;

    ParamterUnitMapType GetParameterUnits() const override;

    ParameterNamesType GetDerivedParameterNames() const override;

    ParametersSizeType  GetNumberOfDerivedParameters() const override;

    ParamterUnitMapType GetDerivedParameterUnits() const override;

    ParameterNamesType GetStaticParameterNames() const override;

    ParametersSizeType GetNumberOfStaticParameters() const override;

    std::string GetModelDisplayName() const override;

    std::string GetModelType() const override;

    FunctionStringType GetFunctionString() const override;

    std::string GetXName() const override;

    std::string GetXAxisName() const override;

    std::string GetXAxisUnit() const override;

    std::string GetYAxisName() const override;

    std::string GetYAxisUnit() const override;


  protected:
    TwoStepLinearModel() {};
    virtual ~TwoStepLinearModel(){};


    /**
     * Actual implementation of the clone method. This method should be reimplemeted
     * in subclasses to clone the extra required parameters.
     */
    virtual itk::LightObject::Pointer InternalClone() const;

    virtual ModelResultType ComputeModelfunction(const ParametersType& parameters) const;
    virtual DerivedParameterMapType ComputeDerivedParameters(const mitk::ModelBase::ParametersType&
        parameters) const;

    virtual void SetStaticParameter(const ParameterNameType& name,
                                    const StaticParameterValuesType& values);
    virtual StaticParameterValuesType GetStaticParameterValue(const ParameterNameType& name) const;

    static double ComputeSignalFromParameters(double x, double t, double a1, double a2, double b1, double b2);

  private:

    //No copy constructor allowed
    TwoStepLinearModel(const Self& source);
    void operator=(const Self&);  //purposely not implemented
  };
}


#endif
