#include <cmath>
#include "TF1.h"

void calibrazione(){

//DEFINIZIONE VARIABILI
const Int_t n=10;
Double_t x[n]={40, 48, 68, 88, 108, 130, 150, 170, 190, 210};
double_t ex[n]={4.18, 2.46, 2.86, 3.31, 3.81, 6.34, 10.97, 7.14, 7.58, 8.04};
Double_t y[n]={31.9, 40, 59.9, 79.3, 100.1, 120.7, 140.5, 160, 180.2, 200.1};
Double_t ey[n]={ 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1};

//DEFINIZIONE GRAFICO
TGraphErrors *gr = new TGraphErrors(n,x,y,ex,ey);
gr->SetTitle("Retta di Calibrazione");
gr->SetMarkerColor(4);
gr->SetMarkerStyle(21);

//CANVA

gr->GetXaxis()->SetTitle("Tensione Multimetro (mV)");
gr->GetYaxis()->SetTitle("Tensione Oscilloscopio (mV)");

//FIT
TF1 *f = new TF1("f","[0]+y*[1]", 0, 300);
f->SetParameter(0,1);
f->SetParNames("Intercetta", "Coefficiente angolare");
gr->Fit("line", "R");
double par[2]={0,1};
f->GetParameters(par);
f->GetParError(0);
f->GetParError(1);
gr->Draw("APE");
}