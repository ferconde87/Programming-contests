#include <bits/stdc++.h>

using namespace std;

typedef long double C;
typedef complex<C> P; //Point

#define X real()
#define Y imag()

C cross_product(P a, P b){
  return (conj(a)*b).Y;
}

// params: p1 and p2 are two points of one line; p3 and p4 are points of another line
// pre: the line segment intersect
// post: output the type of intersection they have
void line_segment_intersection(P p1, P p2, P p3, P p4){
  C cross_a = cross_product(p3-p1,p3-p2);
  C cross_b = cross_product(p4-p1,p4-p2);
  cout << cross_a << " " << cross_b << endl;
  if(cross_a == 0 && cross_b == 0){
    cout << "The line segments are on the same line" << endl;
  }else if(cross_a == 0 || cross_b == 0){
    cout << "The line segments are intersect on one extreme point" << endl;
  }else{
    if(cross_a>0 && cross_b<0 || cross_a<0 && cross_b>0){
      cout << "The line segment intersect in exactly one inner point" << endl;
    }else{
      cout << "The line segment are parellel (but not in the same line)" << endl;
    }
  }
}

int main(){
  P a = {4,2};
  P b = {1,2};
  // • a × b > 0: b turns left
  // • a × b = 0: b does not turn (or turns 180 degrees)
  // • a × b < 0: b turns right
  cout << cross_product(a,b) << endl;

  P x = {3,2};
  P y = {1,4};
  P z = x*y;
  cout << z.X << " " << z.Y << endl;

  // TEST POINT LOCATION
  //if we have a line define by two points like
  // P a = {4,2};
  // P b = {1,2};
  // and a point c
  P c = {5,1};
  C res = cross_product(c-a,c-b);
  if(res > 0){
    cout << "Point c is on the left side of the line defines by a and b " << endl;
  }else if(res < 0){
    cout << "Point c is on the right side of the line defines by a and b " << endl;
  }else{
    //res == 0
    cout << "Point c is on the line (overlap) defines by a and b " << endl;
  }

  // LINE SEGMENT INTERSECTION
  
  //if the line segments intersect...
  // 3 cases
  //case 1 the line segment are on the same line
  P p1 = {2,1};
  P p2 = {3,5};
  P p3 = {1,-3};
  P p4 = {4,9};
  //* one thing we could do is to check the angle of the vectors with respect ot the axis-x
  // if the are in the same line, the angle has to be equal...
  cout << arg(p1-p2) << " " << arg(p3-p4) << endl;
  if(abs(arg(p1-p2)-arg(p3-p4)) < numeric_limits<double>::epsilon()){
    cout << "The line segments are on the same line" << endl;
  }
  //or we can use the cross product using TEST POINT LOCATION with 2 different points, 
  //if two different points are in the same line, then
  //all the points will be.
  if(cross_product(p3-p1,p3-p2)==0 && cross_product(p4-p1,p4-p2)==0){
    cout << "The line segments are on the same line" << endl;
  }

  //case 1 the line segment are on the same line
  line_segment_intersection(p1,p2,p3,p4);
  //case 2 The intersection point is a vertex
  P p5 = {5,7};
  line_segment_intersection(p1,p2,p3,p5);
  //case 3 The line segments have an intersection point that is not a vertex
  P p6 = {1,-2};
  line_segment_intersection(p1,p2,p5,p6);
  //extra case 4 the line are parallel (but they are not in the same segment)
  P p7 = {2,2};
  P p8 = {3,10};
  line_segment_intersection(p1,p2,p7,p8);
}
