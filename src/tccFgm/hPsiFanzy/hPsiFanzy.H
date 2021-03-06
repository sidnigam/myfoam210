/*
Class
    Foam::hPsiFanzy

Description
    * Transport and thermo properties obtained from a FGM table

SourceFiles
    hPsiFanzy.C

*/

#ifndef hPsiFanzy_H
#define hPsiFanzy_H

#include "basicPsiThermo.H"
#include "fanzyLookUp.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

/*---------------------------------------------------------------------------*\
                         Class hPsiFanzy Declaration
\*---------------------------------------------------------------------------*/

class hPsiFanzy
:
    public basicPsiThermo
{
	volScalarField rho_;

        volScalarField Dt_;

        //- Table look up routines
        const fanzyLookUp& fgmTable_;
        
        //- Reference to CV1 & CV2
        const volScalarField& foamCV1_;
        const volScalarField& foamCV2_;
        
        //- FGM table index maps (CpIndex, RIndex, muIndex, alphaIndex)
        const labelList fgmThermoTransportIndices_;
        
    // Private Member Functions

        //- Calculate the thermo variables
        void calculate();

        //- Construct as copy (not implemented)
        hPsiFanzy(const hPsiFanzy&);


public:

    //- Runtime type information
    TypeName("hPsiFanzy");


    // Constructors

        //- Construct from mesh
        hPsiFanzy
        (
            const fvMesh&,
            const fanzyLookUp&,
            const volScalarField&,
            const volScalarField&
        );


    //- Destructor
    ~hPsiFanzy();


    // Member functions

        //- Update properties
        void correct();

	virtual tmp<volScalarField> rho() const
	{
		return rho_;
	}

	virtual volScalarField& rho()
	{
		return rho_;
	}

	tmp<volScalarField> Dt()
	{
		return Dt_;
	}
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

// #include "hPsiFanzyI.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
