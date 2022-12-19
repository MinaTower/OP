#include<iostream>
#include<cmath>
#include <iomanip>
using namespace std;

class icosahedron{
    public:
float edge;
float volume;
float surface_area;
float get_surface_area(float);
float get_volume(float);
};

float icosahedron::get_surface_area(float a)
{
    float area = pow(a, 2)*5*pow(3, 0.5);
    cout << area << ' ' << pow(3, 0.5);
    return area;
}

float icosahedron::get_volume(float a)
{
    float vol = pow(a, 3)*(5*(3 + pow(5, 0.5)))/12;
    return vol;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << " Это программа для расчёта объёма и площади поверхности икосаэдра с заданной длиной ребра" << endl;
    cout << " Введите максимальное количество знаков, отображаемое после запятой: ";
    int precis;
    cin >> precis;
    cout << endl << " Введите длину ребра: ";
    icosahedron ans;
    cin >> ans.edge;
    ans.volume = ans.get_volume(ans.edge);
    ans.surface_area = ans.get_surface_area(ans.edge);
    cout << endl << " Объём данного икосаэдра: " << setprecision(precis) << ans.volume << endl;
    cout << " Площадь поверхности данного икосаэдра: " << setprecision(precis) << ans.surface_area << endl;
    return 0;
}
