/*
�������ַ�������Sƥ��T�����鿴T����û��S��ĳ����׺��
��չkmp��һ��ext[i]���飬��ʾS[i]��Tƥ��������ǰ׺�ĳ��ȡ�
˼���������kmp�ķ������������ظ��Ƚϣ�����ʱ��Ч�ʡ�
����nxt[]���飬nxt[i]��ʾT[i..m]��T�������ǰ׺���ȡ�
i+nxt[i]�ĳ��Ⱦ����ظ��Ӵ�����ѭ���ڵĴ����ĳ���
�����ʱ�临�Ӷ�O(n)
*/

#define M 1020
int nxt[M], ext[M];

void ExtendKmp(char s[], int ls, char t[], int lt) {
    int i, j, k;
    int Len, L;
    j = 0;
    while (t[j + 1] == t[j] && j + 1 < lt) j++;
    nxt[1] = j, k = 1;
    for (i = 2; i < lt; i++) {
        Len = k + nxt[k], L = nxt[i - k];
        if (Len > L + i) nxt[i] = L;
        else {
            j = Len - i > 0 ? Len - i : 0;
            while (t[i + j] == t[j] && i + j < lt) j++;
            nxt[i] = j, k = i;
        }
    }
    j = 0;
    while (s[j] == t[j] && j < lt && j < ls) j++;
    ext[0] = j, k = 0;
    for (i = 1; i < ls; i++) {
        Len = k + ext[k], L = nxt[i - k];
        if (Len > L + i) ext[i] = L;
        else {
            j = Len - i > 0 ? Len - i : 0;
            while (s[i + j] == t[j] && i + j < ls && j < lt) j++;
            ext[i] = j, k = i;
        }
    }
}
