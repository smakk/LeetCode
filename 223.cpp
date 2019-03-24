/*
Rectangle Area https://leetcode.com/problems/rectangle-area/description/
*/

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area1 = abs(D-B)*abs(C-A);
        int area2 = abs(H-F)*abs(G-E);
        if(C<E || A>G || H<B || F>D)
            return area1+area2;
        int lengthright = min(C,G);
        int lengthleft = max(A,E);
        int hightop = min(D,H);
        int highbuttom = max(F,B);
        int area3 = abs(lengthright-lengthleft)*abs(hightop-highbuttom);
        return area1+area2-area3;
    }
};