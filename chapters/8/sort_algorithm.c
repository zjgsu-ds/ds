typedef struct {
    int key;
    float info;
} JD;

void straightsort(JD r[],int n)
{
    int i,j;

    for(i = 2; i <= n; i++) {
        r[0] = r[i];
        j = i-1;
        while(r[0].key < r[j].key) {
            r[j+1] = r[j];
            j--;
        }
        r[j+1] = r[0];
    }
}

void shellsort(JD r[],int n,int d[], int T)
{
    int i, j, k;
    JD x;
    k = 0;
    while(k < T) {
        for(i = d[k]+1; i <= n; i++) {
            x = r[i];
            j = i-d[k];
            while((j>0) && (x.key<r[j].key)) {
                r[j+d[k]] = r[j];
                j = j-d[k];
            }
            r[j+d[k]] = x;
        }

        k++;
    }
}

void bubble_sort(JD r[],int n)
{
    int m, i, j, flag = 1;
    JD x;

    m = n-1;
    while((m>0)&&(flag==1)) {
        flag = 0;
        for(j = 1; j <= m; j++)
            if(r[j].key > r[j+1].key) {
                flag = 1;
                x = r[j];
                r[j] = r[j+1];
                r[j+1] = x;
            }
        m--;
    }
}

void qksort(JD r[],int t, int w)
{
    int i,j,k;
    JD x;

    if(t>=w)  return;
    i=t;
    j=w;
    x=r[i];
    while(i<j) {
        while((i<j)&&(r[j].key>=x.key))  j--;
        if(i<j) {
            r[i]=r[j];
            i++;
        }
        while((i<j)&&(r[i].key<=x.key))  i++;
        if(i<j) {
            r[j]=r[i];
            j--;
        }
    }
    r[i]=x;

    qksort(r, t, j-1);
    qksort(r, j+1, w);
}

void smp_selesort(JD r[],int n)
{
    int i,j,k;
    JD x;

    for(i=1; i<n; i++) {
        k=i;
        for(j=i+1; j<=n; j++)
            if(r[j].key<r[k].key)  k=j;
        if(i!=k) {
            x=r[i];
            r[i]=r[k];
            r[k]=x;
        }
    }
}

#define M 100

void mergesort(JD r[],int n)
{
    int i,s=1;
    JD t[M];

    while(s<n) {
        tgb(s,n,r,t);
        s*=2;
        if(s<n) {
            tgb(s,n,t,r);
            s*=2;
        } else {
            i=1;
            while(i<=n)  r[i]=t[i++];
        }
    }
}

void tgb(int s,int n,JD r[],JD t[])
{
    int i=1;
    while(i<=(n-2*s+1)) {
        merge(r,i,i+s-1,i+2*s-1,t);
        i=i+2*s;
    }
    if(i<(n-s+1))  merge(r,i,i+s-1,n,t);
    else
        while(i<=n)  t[i]=r[i++];
}

void merge(JD r[],int h,int m,int w,JD t[])
{
    int i,j,k;
    i=h;
    j=m+1;
    k=h-1;
    while((i<=m)&&(j<=w)) {
        k++;
        if(r[i].key<=r[j].key)
            t[k]=r[i++];
        else
            t[k]=r[j++];
    }
    if(i>m)
        while(j<=w)  t[++k]=r[j++];
    else
        while(i<=m)  t[++k]=r[i++];
}
