{
gROOT->Reset();
gStyle->SetOptStat(0);
float pi=TMath::Pi();
float N=100;
const float k=0.7007827;
TF1 *f=new TF1("f","[5]*([0]+ [1]*x + [2]*pow(x,2) + [3]*pow(x,3) + [4]*pow(x,4))*sin(x)",0.,pi);
f->SetParameter(0,-0.0158892);
f->SetParameter(1,2.31008);
f->SetParameter(2,-1.73835);
f->SetParameter(3,0.464324);
f->SetParameter(4,-0.0459633);
f->SetParameter(5,k);//Parametro de normalizacion
f->SetLineColor(4);
f->SetTitle("Densidad de fotones contra angulo #theta (#sigma)");
f->GetXaxis()->SetTitle("Angulo #theta [radianes]");
f->GetYaxis()->SetTitle("#sigma [Densidad de Fotones]");

//TF1 *h=new TF1("h","[5]*([0]+ [1]*x + [2]*pow(x,2) + [3]*pow(x,3) + [4]*pow(x,4))",0.,pi);
//h->SetParameter(0,-0.0158892);
//h->SetParameter(1,2.31008);
//h->SetParameter(2,-1.73835);
//h->SetParameter(3,0.464324);
//h->SetParameter(4,-0.0459633);
//h->SetParameter(5,k);//Parametro de normalizacion
//h->SetLineColor(6);
float integral=0;
float maxlim=1.2891, minlim=1.2657;
integral=f->Integral(minlim,maxlim);
cout<<integral<<endl;
//TH1F *g =new TH1F("Derivada","Derivada",N,0.,pi);
//for(int i=1;i<N+1;i++){
//g->SetBinContent(i,f->Derivative(i*(pi/100)));
//}
f->Draw("l");
leg= new TLegend(0.6,0.9,0.9,0.7);
leg->SetFillColor(0);
leg->SetTextSize(0.04);
leg->AddEntry("f","#sigma [fotones/m^{2}]");
leg->Draw("same");

//f->Draw("same");
//h->Draw("same");
}
