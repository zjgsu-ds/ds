
#define M 500
typedef struct {
    int key;
    float info;
} JD;

int seqsrch(JD r[],int n,int k)
{
    int i = n;

    r[0].key = k;
    while(r[i].key != k)
        i--;

    return i;
}

int binsrch(JD r[],int n,int k)
{
    int low, high, mid, found;

    low = 1;
    high = n;
    found = 0;
    while( (low <= high)  && (found == 0) ) {
        mid = (low+high)/2;
        if(k > r[mid].key)  low = mid+1;
        else if(k == r[mid].key)  found = 1;
        else high = mid-1;
    }
    if(found == 1)
        return mid;
    else
        return 0;
}

