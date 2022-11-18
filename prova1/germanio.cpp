void germanio(){

// definizione varibili
Float_t y[11]={0.1, 0.12, 0.27, 0.56, 1, 1.33, 1.77, 2.45, 3.25, 4.32, 5.62};
Float_t ey[11]={0.01, 0.01, 0.01, 0.01, 0.01, 0.01, 0.01, 0.01, 0.01, 0.01, 0.01};
Float_t x[11]={120, 160, 200, 240, 280, 300, 320, 340, 360, 380, 400};
Float_t ex[11]={20.32, 40.29, 40.45, 40.64, 21.69, 21.93, 22.18, 22.45, 22.73, 23.02, 23.32};

// creazione grafico
TGraphErrors *gr = new TGraphErrors(8,x, y, ex, ey);
gr->SetTitle("Diodo al Ge");
gr->SetMarkerStyle(4);

TCanvas *c1 = new TCanvas("canva", "c1");
c1->SetLogy();
c1->SetGrid();
gr->GetXaxis()->SetTitle("Voltaggio (mV)");
gr->GetYaxis()->SetTitle("Corrente (mA)");

// definizione nuova funzione
TF1 *f1 = new TF1("f1","[0]*(exp(x/[1])-1)", 100, 500);
f1->SetParameter(0,1e-6);
f1->SetParameter(1,300);
f1->SetParName(0, "amplitude");
f1->SetParName(1, "Eta_VI");
f1->SetLineColorAlpha(kRed, 0.50);
f1->SetLineWidth(1);
f1->SetLineStyle(1);
gr->Fit("f1", "R");
gr->Draw("AP");
f1->Draw("same");
gStyle->SetOptFit(1111);
}