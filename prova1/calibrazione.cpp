#include <cmath>
#include "TF1.h"

void calibrazione(){

//DEFINIZIONE VARIABILI
const Int_t n=10;
Double_t y[n]={40, 48, 68, 88, 108, 130, 150, 170, 190, 210};
double_t ey[n]={4.18, 2.46, 2.86, 3.31, 3.81, 6.34, 10.97, 7.14, 7.58, 8.04};
Double_t x[n]={31.9, 40, 59.9, 79.3, 100.1, 120.7, 140.5, 160, 180.2, 200.1};
Double_t ex[n]={ 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1};

//DEFINIZIONE GRAFICO
TGraphErrors *gr = new TGraphErrors(n,x,y,ex,ey);
gr->SetTitle("Retta di Calibrazione");
gr->SetMarkerColor(4);
gr->SetMarkerStyle(21);

//CANVA
TCanvas *c1 = new TCanvas();
c1->SetGrid();
gr->GetXaxis()->SetTitle("Tensione Multimetro (mV)");
gr->GetYaxis()->SetTitle("Tensione Oscilloscopio (mV)");

//FIT vanno usate massimo 4 variabili e sono in fila x,y,z,t NON puoi usare solo y sennò segna errore poichè formula bidimensionale
// sta cosa mi fa diventare matto ma è anche divertente, credo che mi servirà del tempo per somatizzare
TF1 *f1 = new TF1("f1","[0]+(x*[1])", 0, 300);
f1->SetParName(0,"intercetta");
f1->SetParName(1,"coeff angolare");
f1->SetParameter(0, 0.1);
f1->SetParameter(1, 10);
gr->Fit("f1", "R");
gr->Draw("APE");
f1->Draw("SAME");
gStyle->SetOptFit(1111);
}