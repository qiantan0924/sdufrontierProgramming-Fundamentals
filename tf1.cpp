void tf1(){
    TF1* f1= new TF1  ("function1","sin(x)*x",-10,10);
    f1->Draw();
}