{
gROOT->Reset();
gStyle->SetOptStat(0);
//#include "TLegend.h"
float pi=TMath::Pi();
//FILE *datos;
//datos = fopen("relax.dat","w");

TFile *f =new TFile ("xray2.root");
TString hnam="GmTrackDataHistosUA_GmGammaFilter:FinalDirPhi";
TH1F *c =(TH1F*)f->Get(hnam);
//caracteristicas del histograma
float maxbins=0,minbins=0,N=0,bin=0;
maxbins=c->GetBinContent(c->GetMaximumBin());
minbins=c->GetBinContent(c->GetMinimumBin());
N=c->GetSize()-2;
TH1F *g =new TH1F("Dist Angular","Distribucion Angular #phi de Rayos X",N,0.,2*pi);
cout<<N<<endl;
//Para normalizar el histograma
for(int i=1;i<N+1;i++){
bin=c->GetBinContent(i)/maxbins;
c->SetBinContent(i,bin);
}//end for
//Para pasar datos a array
float dat[N];
for(int k=0;k<N;k++){ 
dat[k]=c->GetBinContent(k);
g->SetBinContent(k,dat[k]);
g->SetMarkerStyle(21);
}//end for
//Para dibujar el Fit polinomio grado 1
TF1 *r=new TF1("r","([0]+ [1]*x)",0.,2*pi);
r->SetParameter(0,0.907437);
r->SetParameter(1,0.00382193);
r->SetLineColor(4);

g->GetXaxis()->SetTitle("Angulo #phi [rad]");
g->GetYaxis()->SetTitle("Densidad [Unidades Arbitrarias]");
g->Draw("p");
r->Draw("same");

leg= new TLegend(0.5,0.7,0.85,0.5);
leg->SetFillColor(0);
leg->SetTextSize(0.04);
leg->AddEntry("g","Simulacion GAMOS");
leg->AddEntry("r","Fit primer orden");
leg->Draw("same");
}
