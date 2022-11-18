void germanio(){

// definizione varibili
Float_t I[11]={0.1, 0.12, 0.27, 0.56, 1, 1.33, 1.77, 2.45, 3.25, 4.32, 5.62};
Float_t IErr[11]={0.01, 0.01, 0.01, 0.01, 0.01, 0.01, 0.01, 0.01, 0.01, 0.01, 0.01};
Float_t V[11]={120, 160, 200, 240, 280, 300, 320, 340, 360, 380, 400};
Float_t VErr[11]={20.32, 40.29, 40.45, 40.64, 21.69, 21.93, 22.18, 22.45, 22.73, 23.02, 23.32};

// creazione grafico
TGraph *gr = new TGraphErrors(8,I,V,IErr,VErr);
gr->SetTitle("Diodo al Si");
gr->SetMarkerStyle(4);
gr->Draw("APE");

TCanvas *c1 = new TCanvas("canva", "c1");
c1->SetLogy();
gr->GetXaxis()->SetTitle("Voltaggio (mV)");
gr->GetYAxis()->SetTitle("Corrente (mA)");

// definizione nuova funzione
TF1 *f1 = new TF1("f1","[0]*exp(I/[1])-1);
f1->SetParameter(0,1e-6);
f1->SetParameter(1,50);
f1->SetParName(1, "Eta_VI");
gr_<Fit("f1", "R");
gStyleSetOptFit(1111);

}