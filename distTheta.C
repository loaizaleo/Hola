{
gROOT->Reset();
gStyle->SetOptStat(0);
//#include "TLegend.h"
float pi=TMath::Pi();
//FILE *datos;
//datos = fopen("relax.dat","w");

TFile *f =new TFile ("xray2.root");
TString hnam="GmTrackDataHistosUA_GmGammaFilter:FinalDirTheta";
TH1F *c =(TH1F*)f->Get(hnam);
//caracteristicas del histograma
float maxbins=0,minbins=0,N=0,bin=0;
maxbins=c->GetBinContent(c->GetMaximumBin());
minbins=c->GetBinContent(c->GetMinimumBin());
N=c->GetSize()-2;
TH1F *g =new TH1F("Dist Angular","Distribucion Angular #theta de Rayos X",N,0.,pi);
cout<<N<<endl;
//Para normalizar el histograma
for(int i=1;i<N+1;i++){
bin=c->GetBinContent(i)/maxbins;
c->SetBinContent(i,bin);
}//end for
//Para realizar conversion a radianes
float dat[N];
for(int k=0;k<N;k++){ 
dat[k]=c->GetBinContent(k);
g->SetBinContent(k,dat[k]);
g->SetMarkerStyle(21);
}//end for
//for(int m=0;m<N;m++){	
//	fprintf(datos,"%d\t\t%f\n",m,dat[m]);
//}
//Creación archivo de datos
//fprintf(datos,"\n");
//	fclose(datos);//Creación archivo de datos
TF1 *r=new TF1("r","([0]+ [1]*x + [2]*pow(x,2) + [3]*pow(x,3) + [4]*pow(x,4))",0.,pi);
r->SetParameter(0,-0.0158892);
r->SetParameter(1,2.31008);
r->SetParameter(2,-1.73835);
r->SetParameter(3,0.464324);
r->SetParameter(4,-0.0459633);
r->SetLineColor(4);

g->GetXaxis()->SetTitle("Angulo #theta [rad]");
g->GetYaxis()->SetTitle("Densidad [Unidades Arbitrarias]");

g->Draw("p");
r->Draw("same");
leg= new TLegend(0.6,0.9,0.9,0.7);
leg->SetFillColor(0);
leg->AddEntry("g","Simulacion GAMOS");
leg->AddEntry("r","Fit cuarto orden");
leg->Draw("same");
}
