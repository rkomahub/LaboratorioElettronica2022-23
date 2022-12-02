Double_t line1(Double_t *x, Double_t *par){
Float_t xx=x[0];
Double_t val=(par[0]+par[1]*xx);
return val;
}

Double_t line2(Double_t *x, Double_t *par){
Float_t xxx=x[0];
Double_t val=(par[0]+par[1]*xxx);
return val;
}

void transistor(){

// Costruzione grafico Ic-Vce per Ib=-0.2mA
TGraphErrors *g1 = new TGraphErrors("./dati1bis.txt","%lg %lg %lg %lg"); // solo da fittare
g1->SetTitle("Caratteristica I-V");
g1->GetXaxis()->SetTitle("Tensione V_CE(V)");
g1->GetYaxis()->SetTitle("Corrente I_C(mA)");
g1->SetMarkerStyle(21);

TGraphErrors *g3 = new TGraphErrors("./dati1.txt","%lg %lg %lg %lg"); // solo da graficare
g3->SetTitle("Caratteristica I-V");
g3->GetXaxis()->SetTitle("Tensione V_CE(V)");
g3->GetYaxis()->SetTitle("Corrente I_C(mA)");
g3->SetMarkerStyle(21);

// Fit lineare per il grafico a Ib=-0.2mA
TF1 *f1 = new TF1("fit1",line1,40,60,2); // 2 indica il numero dei parametri
f1->SetParameters(10,10); // parametri già dichiarati nella funzione line esterna alla macro
f1->SetParNames("Tensione Early_1","Resistenza di uscita_1");
g1->Fit("fit1","","",42,60);

// Costruzione grafico Ic-Vce per Ib=-0.1mA
TGraphErrors *g2 = new TGraphErrors("./dati2bis.txt","%lg %lg %lg %lg");
g2->SetTitle("Caratteristica I-V");
g2->GetXaxis()->SetTitle("Tensione V_CE(V)"); 
g2->GetYaxis()->SetTitle("Corrente I_C(mA)");
g2->SetMarkerStyle(22);

TGraphErrors *g4 = new TGraphErrors("./dati2.txt","%lg %lg %lg %lg");
g4->SetTitle("Caratteristica I-V");
g4->GetXaxis()->SetTitle("Tensione V_CE(V)"); 
g4->GetYaxis()->SetTitle("Corrente I_C(mA)");
g4->SetMarkerStyle(22);

// Fit lineare per I grafico a Ib=-0.1mA
TF1 *f2 = new TF1("fit2",line2,26,35,2);
f2->SetParameters(10,10);
f2->SetParNames("Tensione di Early_2","Resistenza di uscita_2");
g2->Fit("fit2","R");

// Impostare MultiGraph
TCanvas *graph = new TCanvas("graph","graph");
auto mg2 = new TMultiGraph;
mg2->SetTitle("Caratteristica I-V ; Corrente I_C(mA); Tensione V_CE(V)");
mg2->Add(g3);
mg2->Add(g4);
mg2->Draw("apl");

TCanvas *check = new TCanvas("check","check");
auto mg1 = new TMultiGraph;
mg1->SetTitle("Check fit; Tensione V_CE(V); Corrente I_C(mA)");
mg1->Add(g1);
mg1->Add(g2);
mg1->Draw("apl");

// Stampa parametri fit
std::cout<<"Tensione Early a_1 = ("<<f1->GetParameter(0)<<" +/- "<<f1->GetParError(0)<<") V"<<endl;
std::cout<<"Resistenza di uscita b_1 = ("<<f1->GetParameter(1)<<" +/- "<<f1->GetParError(1)<<") kOhm"<<endl;
std::cout<<"Tensione Early a_2 = ("<<f2->GetParameter(0)<<" +/- "<<f2->GetParError(0)<<") V"<<endl;
std::cout<<"Resistenza di uscita b_2 = ("<<f2->GetParameter(1)<<" +/- "<<f2->GetParError(1)<<") kOhm"<<endl;

std::cout<<"Conduttanza in uscita g_1 = ("<<1/f1->GetParameter(1)<<"+/-"<<(f1->GetParError(1))/(f1->GetParameter(1)*f1->GetParameter(1))<<") 1/kOhm"<<endl;
std::cout<<"Conduttanza in uscita g_2 = ("<<1/f2->GetParameter(1)<<"+/-"<<(f2->GetParError(1))/(f2->GetParameter(1)*f1->GetParameter(1))<<") 1/kOhm"<<endl;
};