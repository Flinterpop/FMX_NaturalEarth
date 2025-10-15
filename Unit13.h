//---------------------------------------------------------------------------

#ifndef Unit13H
#define Unit13H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Objects.hpp>
#include <FMX.Types.hpp>
//---------------------------------------------------------------------------
class TForm13 : public TForm
{
__published:	// IDE-managed Components
	TImage *IC_Main;
	void __fastcall IC_MainMouseMove(TObject *Sender, TShiftState Shift, float X, float Y);

private:	// User declarations
public:		// User declarations
	__fastcall TForm13(TComponent* Owner);

	void __fastcall DrawRect(TCanvas *c,TRect MyRect, unsigned int tc);
	void __fastcall FillRect(TCanvas *c,TRect MyRect, unsigned int tc,float alpha);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm13 *Form13;
//---------------------------------------------------------------------------
#endif
