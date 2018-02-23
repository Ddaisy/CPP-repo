/*           *\
  RMQ  simple
\*           */
#define N 10500
#define Mod 1000
int st[20][N], val[N];
/*get Max*/
void makermq(int n) {
    for (int j = 0; j < n; ++j)
        st[0][j] = val[j];
    for (int i = 0; i + 1 < 20; ++i)
        for (int j = 0; j + (1 << i) < n; ++j)
            st[i + 1][j] = max(st[i][j], st[i][j + (1 << i)]);
}
// [begin, end) end δȡ��

int query(int begin, int end) {//max{val[begin],val[begin + 1]......val[end - 1]}
    int k = 0;
    while ((1 << (k + 1)) < end - begin) 
		++k;
    return max(st[k][begin], st[k][end - (1 << k)]);
}

/*==================================================================*\
\*==================================================================*/

/*get Min*/
void makermq(int n) {
    for (int j = 0; j < n; ++j)
        st[0][j] = val[j];
    for (int i = 0; i + 1 < 20; ++i)
        for (int j = 0; j + (1 << i) < n; ++j)
            st[i + 1][j] = min(st[i][j], st[i][j + (1 << i)]);
}
// [begin, end) end δȡ��

int query(int begin, int end) {//min{val[begin],val[begin + 1]......val[end - 1]} ��΢�е�죬����û��Ԥ����log���Ŀ�
    int k = 0;
    while ((1 << (k + 1)) < end - begin)
        ++k;
    return min(st[k][begin], st[k][end - (1 << k)]);
}




