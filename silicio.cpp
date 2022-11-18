void silicio(){

// definizione varibili
Float_t y[8]={0.1, 0.21, 0.41, 1.03, 2.22, 4.29, 8.46, 14.84};
Float_t ey[8]={0.01, 0.01, 0.01, 0.01, 0.01, 0.01, 0.01, 0.01};
Float_t x[8]={520, 560, 600, 640, 680, 720, 760, 800};
Float_t ex[8]={42.93, 43.38, 43.86, 44.37, 44.90, 45.46, 46.04, 46.65};

// creazione grafico
TGraphErrors *gr = new TGraphErrors(8,x, y, ex, ey);
gr->SetTitle("Diodo al Si");
gr->SetMarkerStyle(4);

TCanvas *c1 = new TCanvas("canva", "c1");
c1->SetLogy();
c1->SetGrid();
gr->GetXaxis()->SetTitle("Voltaggio (mV)");
gr->GetYaxis()->SetTitle("Corrente (mA)");

// definizione nuova funzione
TF1 *f1 = new TF1("f1","[0]*exp(x/[1])-1", 500, 800);
f1->SetParameter(0,1e-6);
f1->SetParameter(1,50);
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