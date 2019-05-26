#include <iostream>
using namespace std;

typedef struct point {
    char c; int x, y;
}point;

typedef struct line {
    point p1, p2;
}line;


typedef struct head {
    point p1;
    float Angle;
}head;

point *a, *polygon, z;

class HEAP {
private:
    head *a;
    int index = 0;
public:
    HEAP(int max) {
        a = new head[max];
    }
    ~HEAP() {
        delete a;
    }

    void swap(head a[], int i, int j) {
        head temp;
        temp = a[j]; a[j] = a[i]; a[i] = temp;
    }

    void MakeHeap(head a[], int Root, int LastNode) {
        int Parent, LeftSon, RightSon, Son;
        head RootValue;
        Parent = Root;
        RootValue = a[Root];
        LeftSon = 2 * Parent + 1;
        RightSon = LeftSon + 1;
        while (LeftSon <= LastNode) {
            if (RightSon <= LastNode && a[LeftSon].Angle < a[RightSon].Angle) {
                Son = RightSon;
            }
            else {
                Son = LeftSon;
            }
            if (RootValue.Angle < a[Son].Angle) {
                a[Parent] = a[Son];
                Parent = Son;
                LeftSon = Parent * 2 + 1;
                RightSon = LeftSon + 1;
            }
            else {
                break;
            }
        }
        a[Parent] = RootValue;
    }

    void heapsort(head a[], int n) {
        int i;
        for (i = n / 2; i >= 1; i--) MakeHeap(a, i - 1, n - 1);
        for (i = n - 1; i >= 1; i--) {
            swap(a, 0, i);
            MakeHeap(a, 0, i - 1);
        }
    }
    head *get_a() {
        return a;
    }

    void makearray(head *a, point p, float t) {
        a[index].p1 = p;
        a[index++].Angle = t;
    }
};

float ComputeAngle(point p1, point p2) {
    int dx, dy, ax, ay;
    float t;
    dx = p2.x - p1.x; ax = abs(dx);
    dy = p2.y - p1.y; ay = abs(dy);
    t = (ax + ay == 0) ? 0 : (float)dy / (ax + ay);
    if (dx < 0) t = 2 - t; else if (dy < 0) t = 4 + t;
    return (t * 90.0);
}

int Direction(point A, point B, point C) {
    int dxAB, dxAC, dyAB, dyAC, dir;
    dxAB = B.x - A.x; dyAB = B.y - A.y;
    dxAC = C.x - A.x; dyAC = C.y - A.y;
    if (dxAB * dyAC < dyAB * dxAC) dir = 1;
    if (dxAB * dyAC > dyAB * dxAC) dir = -1;
    if (dxAB * dyAC == dyAB * dxAC) {
        if (dxAB == 0 && dyAB == 0) dir = 0;
        if ((dxAB * dxAC) < 0 || (dyAB * dyAC < 0)) dir = -1;
        else if ((dxAB * dxAB + dyAB * dyAB) >= (dxAC * dxAC + dyAC * dyAC)) dir = 0;
        else dir = 1;
    }
    return dir;
}

bool Intersection(line AB, line CD) {
    bool LineCrossing;
    if ((Direction(AB.p1, AB.p2, CD.p1) * Direction(AB.p1, AB.p2, CD.p2) <= 0) && (Direction(CD.p1, CD.p2, AB.p1) * Direction(CD.p1, CD.p2, AB.p2) <= 0))
        LineCrossing = true;
    else LineCrossing = false;
    return LineCrossing;
}

int IsPointInside(point A, point p[], int n) {
    int Count, i;
    int LastPoint;
    bool PointOnTestLine = false;
    line TestLine, PolyLine;
    Count = LastPoint = 0;
    TestLine.p1 = A; TestLine.p2 = A;
    TestLine.p2.x = INT_MAX;

    for (i = 1; i < n; i++) {
        PolyLine.p1 = PolyLine.p2 = p[i];
        if (TestLine.p1.x <= p[i].x && TestLine.p1.y == p[i].y)
            PointOnTestLine = true;
        else {
            PolyLine.p1 = p[LastPoint];
            LastPoint = i;
            if (!PointOnTestLine) {
                if (Intersection(PolyLine, TestLine)) {
                    Count++;
                    if ((TestLine.p1.y > PolyLine.p1.y && TestLine.p1.y > PolyLine.p2.y) ||
                        (TestLine.p1.y < PolyLine.p1.y && TestLine.p1.y < PolyLine.p2.y))
                        Count--;
                }
            }
            else {
                if (Direction(TestLine.p1, TestLine.p2, PolyLine.p1) *
                    Direction(TestLine.p1, TestLine.p2, PolyLine.p2) < 0) {
                    Count++;
                    if ((TestLine.p1.y > PolyLine.p1.y && TestLine.p1.y > PolyLine.p2.y) || (TestLine.p1.y < PolyLine.p1.y && TestLine.p1.y < PolyLine.p2.y))
                        Count--;
                }
                PointOnTestLine = false;
            }
        }
    }
    return (Count % 2);
}

int main() {
    int n;
    point *minpointer = NULL;
    cin >> n >> z.x >> z.y;
    z.c = 'z';
    a = new point[8];
    polygon = new point[8];
    HEAP H(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i].c >> a[i].x >> a[i].y;
        if (i == 0) minpointer = &a[0];
        else if (minpointer->y > a[i].y) minpointer = &a[i];
        else if (minpointer->y == a[i].y){
            if (minpointer->x > a[i].x)
                minpointer = &a[i];
        }
    }

    for (int i = 0; i < n; i++) {
        H.makearray(H.get_a(), a[i], ComputeAngle(a[i], *minpointer));
    }
    H.heapsort(H.get_a(), n);
    for (int i = 0; i < n; i++){
        polygon[i] = (H.get_a() + i)->p1;
    }

    if (IsPointInside(z, polygon, n)) cout << "TRUE" << endl;
    else cout << "FALSE" << endl;

    return 0;
}