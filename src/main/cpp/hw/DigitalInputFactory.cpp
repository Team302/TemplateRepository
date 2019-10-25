
///====================================================================================================================================================
/// Copyright 2019 Lake Orion Robotics FIRST Team 302
///
/// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"),
/// to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
/// and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
///
/// The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
///
/// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
/// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
/// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE
/// OR OTHER DEALINGS IN THE SOFTWARE.
///====================================================================================================================================================

///========================================================================================================
/// DigitalInputFactory.cpp
///========================================================================================================
///
/// File Description:
///     This controls the creation of Digital inputs
///
///========================================================================================================

// C++ Includes
#include <iostream>

// FRC includes

// Team 302 includes
#include <hw/DigitalInputFactory.h>
#include <hw/DragonDigitalInput.h>


// Third Party Includes




///=====================================================================================
/// Method:         GetFactory
/// Description:    Find or create the Digital input factory
/// Returns:        DigitalInputFactory* pointer to the factory
///=====================================================================================
DigitalInputFactory* DigitalInputFactory::m_factory = nullptr;
DigitalInputFactory* DigitalInputFactory::GetFactory()
{
	if ( DigitalInputFactory::m_factory == nullptr )
	{
		DigitalInputFactory::m_factory = new DigitalInputFactory();
	}
	return DigitalInputFactory::m_factory;
}


///=====================================================================================
/// Method:         CreateInput
/// Description:    Create the requested Digital input
/// Returns:        IMechanism*     pointer to the mechanism or nullptr if mechanism 
///                                 doesn't exist and cannot be created.
///=====================================================================================
DragonDigitalInput* DigitalInputFactory::CreateInput
(
    DragonDigitalInput::DIGITAL_INPUT_TYPE			type,
    int 						                    digitalID,
    bool						                    reversed
)
{
    DragonDigitalInput* sensor = nullptr;
    switch ( type )
    {
        case DragonDigitalInput::ARM_MIN_POSITION:
            sensor = m_armExtendMin == nullptr ? new DragonDigitalInput( type, digitalID, reversed ) : m_armExtendMin;
            break;

        default:
            std::cout << "==>>DigitalInputFactory::CreateInput unknown type " << type << std::endl;
            break;
    }
    return sensor;
}


///=====================================================================================
/// Method:         GetInput
/// Description:    Get the requested Digital input
/// Returns:        IMechanism*     pointer to the mechanism or nullptr if mechanism 
///                                 doesn't exist.
///=====================================================================================
DragonDigitalInput* DigitalInputFactory::GetInput
(
    DragonDigitalInput::DIGITAL_INPUT_TYPE			type
)
{
    DragonDigitalInput* sensor = nullptr;
    switch ( type )
    {
        case DragonDigitalInput::ARM_MIN_POSITION:
            sensor = m_armExtendMin;
            break;

        default:
            std::cout << "==>>DigitalInputFactory::GetInput unknown type " << type << std::endl;
            break;
    }
    return sensor;
}

DigitalInputFactory::DigitalInputFactory()
{
    m_armExtendMin = nullptr;
}

DigitalInputFactory::~DigitalInputFactory()
{
    if ( m_armExtendMin != nullptr )
    {
        delete m_armExtendMin;
        m_armExtendMin = nullptr;
    }
}