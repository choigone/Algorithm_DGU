#include <iostream>
using namespace std;

typedef struct point {
    char c; int x, y;
}point;

typedef struct head {
    point p1;
    float Angle;
}head;

point *a, *polygon;
int cnt1 = 0;
int cnt2 = 0;

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
                cnt2++;
            }
            else {
                Son = LeftSon;
                cnt2++;
            }
            if (RootValue.Angle < a[Son].Angle) {
                cnt2++;
                a[Parent] = a[Son];
                Parent = Son;
                LeftSon = Parent * 2 + 1;
                RightSon = LeftSon + 1;
            }
            else {
                cnt2;
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

    void swap(head a[], int i, int j) {
        head temp;
        temp = a[j]; a[j] = a[i]; a[i] = temp;
    }
};

float ComputeAngle(point p1, point p2) {
    int dx, dy, ax, ay;
    float t;
    cnt1++;
    dx = p2.x - p1.x; ax = abs(dx);
    dy = p2.y - p1.y; ay = abs(dy);
    t = (ax + ay == 0) ? 0 : (float)dy / (ax + ay);
    if (dx < 0) t = 2 - t;
    else if (dy < 0) t = 4 + t;
    return (t * 90.0);
}

int main() {
    int n;
    point *minpointer = NULL;
    cin >> n;
    a = new point[n];
    polygon = new point[n];
    HEAP H(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i].c >> a[i].x >> a[i].y;

        if (i == 0) minpointer = &a[0];
        else if (minpointer->y > a[i].y) minpointer = &a[i];
        else if (minpointer->y == a[i].y){
            if (minpointer->x > a[i].x) minpointer = &a[i];
        }
    }

    for (int i = 0; i < n; i++) {
        H.makearray(H.get_a(), a[i], ComputeAngle(a[i], *minpointer));
    }
    H.heapsort(H.get_a(), n);
    for (int i = 0; i < n; i++) {
        polygon[i] = (H.get_a() + i)->p1;
    }

    cout << cnt1 << " (수평각 계산 횟수)" << endl;
    cout << cnt2 << " (각의 비교 횟수)" << endl;

    return 0;
}