You are given  triangles, specifically, their sides ,  and . Print them in the same style but sorted by their areas from the smallest one to the largest one. It is guaranteed that all the areas are different.

The best way to calculate a area of a triangle with sides ,  and  is Heron's formula:

 where .

Input Format

The first line of each test file contains a single integer .  lines follow with three space-separated integers, ,  and .

Constraints

, and 
Output Format

Print exactly  lines. On each line print  space-separated integers, the ,  and  of the corresponding triangle.

Sample Input 0

3
7 24 25
5 12 13
3 4 5
Sample Output 0

3 4 5
5 12 13
7 24 25
Explanation 0

The area of the first triangle is . The area of the second triangle is . The area of the third triangle is . So the sorted order is the reverse one.

###################################CODE########################################3

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;

double area(triangle tr) {
    double p = (tr.a + tr.b + tr.c) / 2.0;
    return sqrt(p * (p - tr.a) * (p - tr.b) * (p - tr.c));
}

int compare(const void *a, const void *b) {
    triangle *t1 = (triangle*) a;
    triangle *t2 = (triangle*) b;
    double area1 = area(*t1);
    double area2 = area(*t2);
    if (area1 > area2) {
        return 1;
    } else if (area1 < area2) {
        return -1;
    } else {
        return 0;
    }
}

void sort_by_area(triangle* tr, int n) {
    qsort(tr, n, sizeof(triangle), compare);
}

int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}
