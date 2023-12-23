#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

//Normalize function that will be used later on
vector<double> normalize(const vector<double>& v){
  double length = sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
  return {v[0]/ length, v[1]/ length, v[2]/ length};
};

//Function to calculate the cross product between u1 and u2
vector<double> crossProduct(const vector<double>& a, const vector<double>& b) {
    return {a[1]*b[2] - a[2]*b[1], a[2]*b[0] - a[0]*b[2], a[0]*b[1] - a[1]*b[0]};
};

int main() {

  //Initialise our three vectors
  vector<double> V1 = {0, 0 , 0}, V2 = {0, 0 , 0}, V3 = {0, 0, 0}; 
  
  //For loop to grab our vector components
  for(int i = 0; i < 3; i++){
    double n;
    
    cout << "Enter vector " << i + 1 << "'s x coordinate: ";
    cin >> n;

    switch(i)
      {
        case 0: V1[0] = n; break;
        case 1: V2[0] = n; break;
        case 2: V3[0] = n; break;
        default: break;
      }

    cout << "Enter vector " << i + 1 << "'s y coordinate: ";
    cin >> n;
      
    switch(i)
    {
      case 0: V1[1] = n; break;
      case 1: V2[1] = n; break;
      case 2: V3[1] = n; break;
      default: break;
    }

    cout << "Enter vector " << i + 1 << "'s z coordinate: ";
    cin >> n;

    switch(i)
      {
        case 0: V1[2] = n; break;
        case 1: V2[2] = n; break;
        case 2: V3[2] = n; break;
        default: break;
      }
  }

  //Show our user their desired vectors 
  cout << endl << "The entered vectors are: " << endl << endl;
  cout << "Vector 1: (" << V1[0] << ", " << V1[1] << ", " << V1[2] << ")" << endl;
  cout << "Vector 2: (" << V2[0] << ", " << V2[1] << ", " << V2[2] << ")" << endl;
  cout << "Vector 3: (" << V3[0] << ", " << V3[1] << ", " << V3[2] << ")" << endl;

  //Normalize our vectors by making them orthogonal, then normalizing them to make them orthonormal
  //Starting with Vector U1 being equal to V1
  vector<double> u1 = normalize(V1);
  //Then, turning our function to code to handle U2, and U3
  vector<double> u2 = normalize({V2[0] - (V2[0] * u1[0]) * u1[0], V2[1] - (V2[1] * u1[1]) * u1[1], V2[2] - (V2[2] * u1[2]) * u1[2]});
  // Calculate u3 by taking the cross product of u1 and u2, then normalize
  vector<double> u3 = normalize(crossProduct(u1, u2));

  //Show our orthonormal vectors
  cout << endl << "The orthonormal vectors are: " << endl << endl;
  cout << "Vector 1: (" << u1[0] << ", " << u1[1] << ", " << u1[2] << ")" << endl;
  cout << "Vector 2: (" << u2[0] << ", " << u2[1] << ", " << u2[2] << ")" << endl;
  cout << "Vector 3: (" << u3[0] << ", " << u3[1] << ", " << u3[2] << ")" << endl;
  
  return 0;
}
