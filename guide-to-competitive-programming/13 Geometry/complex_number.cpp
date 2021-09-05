#include <bits/stdc++.h>

using namespace std;

typedef long double C;
typedef complex<C> P; //Point

#define X real()
#define Y imag()

int main(){
  complex<long long> point = {4,2};
  cout << point.real() << " " << point.imag() << endl;
  P p = {4,2};
  cout << p.X << " " << p.Y << endl;
  P v = {3,1};
  P u = {2,2};
  P s = v+u;
  cout << s.X << " " << s.Y << endl;
  P a = {4,2};
  P b = {3,-1};
  cout << "distance: " << abs(a-b) << endl;
  //The function arg(v) calculates the angle of a vector v = (x, y) with respect to the x-axis in radiants
  cout << "angle of {3,1} with respect to the axis-x " << arg(v) << endl;
  P v1 = {2,0};
  cout << "angle of {2,0} with respect to the axis-x " << arg(v1) << endl;
  P v2 = {-2,0};
  cout << "angle of {-2,0} with respect to the axis-x " << arg(v2) << endl;
  P v3 = {0,2};
  cout << "angle of {0,2} with respect to the axis-x " << arg(v3) << endl;
  P v4 = {0,-2};
  cout << "angle of {0,2} with respect to the axis-x " << arg(v4) << endl;

  //The function polar(s, a) constructs a vector whose length is s and that points
  //to an angle a, given in radians
  P w = polar(1.0, 0.5);
  //A vector can be rotated by an angle a by multiplying
  //it by a vector with length 1 and angle a.
  //here we rotate 'a' by 0.5 radiant ~ 28.65 DEGREES
  cout << "vector a before rotation by 0.5 radiant = " << a.X << " " << a.Y << endl;
  cout << "the angle of 'a' (in radiants) BEFORE rotation is " << arg(a) << endl;
  cout << "the distance of 'a' to (0,0) BEFORE is " << abs(a) << endl;
  a *= w;
  cout << "here we rotate 'a' by 0.5 radiant > " << a.X << " " << a.Y << endl;
  cout << "the angle of 'a' (in radiants) AFTER rotation is " << arg(a) << endl;
  cout << "the distance of 'a' to (0,0) AFTER doesn't change, so it is the same as before " << abs(a) << endl;

  double pi = 2 * acos(0.0);
  P x = polar(1.0, pi);
  P y = {3,5};
  P inv_y = y*x;
  cout << inv_y.X << " " << inv_y.Y << endl;//-3,-5

}

