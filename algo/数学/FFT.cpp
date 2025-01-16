const double pi = acos(-1);
const int N = 4e6+5;

struct Complex{
    double real,imag;
    Complex(double a=0,double b=0):real(a),imag(b){}
    friend Complex operator+(const Complex& a,const Complex& b){
        return {a.real+b.real, a.imag+b.imag};
    }
    friend Complex operator-(const Complex& a,const Complex& b){
        return {a.real-b.real, a.imag-b.imag};
    }
    friend Complex operator*(const Complex& a,const Complex& b){
        return {a.real*b.real-a.imag*b.imag, a.real*b.imag+a.imag*b.real};
    }
};


int rev[N];

void fft(Complex* f,int n,bool flag){
    for(int i=0;i<n;i++){
        if(i<rev[i])swap(f[i],f[rev[i]]);
    }

    for(int p=2;p<=n;p<<=1){
        Complex wn{cos(2*pi/p),sin(2*pi/p)};
        if(flag)wn.imag=-wn.imag;
        for(int j=0;j<n;j+=p){
            Complex w{1,0};
            for(int k=j;k<j+p/2;k++){
                Complex t = f[k+p/2] * w;
                f[k+p/2] = f[k] - t;
                f[k] = f[k] + t;
                w = w * wn;
            }
        }
    }

    if(flag)for(int i=0;i<n;i++)f[i].real/=n,f[i].imag/=n;
}

Complex f[N],g[N];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    int n,m;cin>>n>>m;
    for(int i=0;i<=n;i++)cin>>f[i].real;
    for(int i=0;i<=m;i++)cin>>g[i].real;

    for(m+=n,n=1;n<=m;n<<=1);
    for(int i=0;i<n;i++){
        rev[i]=rev[i>>1]>>1;
        if(i&1)rev[i]|=n>>1;
    }

    fft(f,n,0);fft(g,n,0);
    for(int i=0;i<n;i++)f[i]=f[i]*g[i];
    fft(f,n,1);
    for(int i=0;i<=m;i++){
        cout<<(int)round(f[i].real)<<' ';
    }
    cout<<'\n';
    return 0;
}