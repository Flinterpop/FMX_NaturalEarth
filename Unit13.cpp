//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Unit13.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm13 *Form13;
//---------------------------------------------------------------------------
__fastcall TForm13::TForm13(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm13::DrawRect(TCanvas *c,TRect MyRect, unsigned int tc)
{
	c->Stroke->Kind = TBrushKind::Solid;
	c->Stroke->Color = claRed;
	c->Stroke->Thickness  = 1.0;
	c->DrawRect(MyRect, 0, 0, AllCorners, 1);
}

void __fastcall TForm13::FillRect(TCanvas *c,TRect MyRect, unsigned int tc,float alpha)
{
	//c->Stroke->Kind = TBrushKind::Solid;
	c->Fill->Color = tc;
	//c->Stroke->Thickness  = 1.0;
	c->FillRect(MyRect, 0, 0, AllCorners,alpha);
}



void __fastcall TForm13::IC_MainMouseMove(TObject *Sender, TShiftState Shift, float X,
          float Y)
{
	//
	double lng = -180.0 + (360.0/1600.0) * X;
	double lat = -90.0 + (180.0/800.0) * Y;


	char buf[100];
    sprintf(buf," %d  %d\r\n %7.4f  %8.4f", (int)X, (int)Y,lat, lng);
	IC_Main->Bitmap->Canvas->BeginScene();

		TRect Dest( 200, 200, 800, 400);
		FillRect(IC_Main->Bitmap->Canvas,Dest, claWhite,1.0);


		IC_Main->Bitmap->Canvas->Stroke->Color = claRed;
		IC_Main->Bitmap->Canvas->Fill->Color = claBlack;
		IC_Main->Bitmap->Canvas->Font->Size = 60.0;// * scale;

		//the next line seems to cause exceptions
		IC_Main->Bitmap->Canvas->FillText(Dest, buf, true, 1.0, TFillTextFlags(), TTextAlign::Leading);//,TTextAlign::Leading);

	IC_Main->Bitmap->Canvas->EndScene();
}
//---------------------------------------------------------------------------
