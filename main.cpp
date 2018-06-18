#include <iostream>
#include <stdlib.h> 
#include <string.h>
#include <math.h>

//$>./computor "5 * X^0 + 4 * X^1 - 9.3 * X^2 = 1 * X^0" 
void 		ft_exception(std::string text)
{
	std::cout<<text<<std::endl;
	exit(0);
}

double 		ft_abs(double n)
{
	return(n < 0 ? -n : n);
}

/*Log base 2 approximation and Newton's Method*/
float		ft_sqrt(const float x)  
{
	union
	{
 		int i;
		float x;
	}	u;

	u.x = x;
	u.i = (1 << 29) + (u.i >> 1) - (1 << 22); 
	return (u.x);
} 

int solve(double a, double b, double c)
{
	double d, x1 ,x2;
 
	if (a == 0 && c == 0 && b == 0)
	{
		std::cout<<"Equation degree: 1"<<std::endl;
		std::cout<<"The solution is: "<<std::endl<<"0 = 0"<<std::endl;
		return (0);
	}
	if (a == 0 && c == 0)
	{
		std::cout<<"Equation degree: 1"<<std::endl;
		std::cout<<"The solution is: "<<std::endl<<"0"<<std::endl;
		return (0);
	} 
	else if (a == 0 && b == 0)
	{
		std::cout<<"Equation degree: 0"<<std::endl;
		std::cout<<"There is no solution. "<<std::endl;
		return (0);
	}
	else if (c == 0)
	{
		std::cout<<"Equation degree: 2"<<std::endl;
		std::cout<<"The solution is: "<<std::endl<<(-b)/a<<std::endl<<"0"<<std::endl;
		return (0);
	}
	else if (a == 0)
	{
		std::cout<<"Equation degree: 1"<<std::endl;
		std::cout<<"The solution is: "<<std::endl<<(-c)/b<<std::endl;
		return (0);
	} 
	d = b * b - 4 * a * c;
	if (d > 0)
	{
		x1 = (-b + ft_sqrt(d)) / (2 * a);
		x2 = (-b - ft_sqrt(d)) / (2 * a);
		std::cout<<"Equation degree: 2"<<std::endl;
		std::cout<<"The solution is: "<<std::endl<<x1<<std::endl<<x2<<std::endl;
	}
	else if (d == 0)
	{
		x1 = (-b) / (2 * a);
		std::cout<<"Equation degree: 2"<<std::endl;
		std::cout<<"The solution is: "<<std::endl<<x1<<std::endl;
	}
	else if (d < 0)
	{
		std::cout<<"Equation degree: 2"<<std::endl;
		std::cout<<"The solution is (non real): "<<std::endl;
		std::cout<< (-b / (2 * a)) << " + "<<(ft_sqrt(-d)) / (2 * a)<< "i"<<std::endl;
		std::cout<< (-b / (2 * a)) << " - "<<(ft_sqrt(-d)) / (2 * a)<< "i"<<std::endl;
	}
	return (1);
}

int			main(int argc, char const **argv)
{
	double a, b, c, temp, rs;
	a = b = c = temp = 0.0;
	std::string str, num;

	if (argc != 2)
		ft_exception("Wrong input: parameter count");
	rs = 1;
	str = argv[1];
	for (unsigned long i = 0; i < str.length(); i++)
	{
		//number
		if (isdigit(str[i]))
		{
			while (isdigit(str[i]))
			{
				num.push_back(str[i]);
				i++;
			}
			if (str[i] == '.')
			{
				num.push_back(str[i]);
				i++;
				while (isdigit(str[i]))
				{
					num.push_back(str[i]);
					i++;
				}
			}
			temp = atof(num.c_str()) * rs;
			// std::cout<<temp<<std::endl;
			if (str[i] != ' ')
				ft_exception("Wrong format: space missed");
			if (str[++i] != '*')
				ft_exception("Wrong format: * missed");
			if (str[++i] != ' ')
				ft_exception("Wrong format: space missed");
			if (str[++i] != 'X')
				ft_exception("Wrong format: X mssied");
			if (str[++i] != '^')
				ft_exception("Wrong format: sign after X");
			if (!isdigit(str[++i]))
				ft_exception("Wrong format: degree");
			if (str[i] == '0')
				c += temp;
			else if (str[i] == '1')
				b += temp;
			else if (str[i] == '2')
				a += temp;
			else if (temp == 0)
				c += temp; // do nothing temp =0
			else
				ft_exception("The polynomial degree is stricly greater than 2, I can't solve.");
			num = "";
		}
		else if (str[i] == '-')
		{
			if(num[0] == '-')
				ft_exception("Wrong format: too much -");
			num.insert(0, "-");
		}
		else if (str[i] == '+')
		{
			continue;
		}
		else if (str[i] == '=')
		{
			if (rs == -1)
				ft_exception("Wrong format: too much =");
			if (str[i + 1] != ' ')
				ft_exception("Wrong format: space missed after =");
			if (!(isdigit(str[i + 2]) || str[i + 2] == '-'))
				ft_exception("Wrong format: rigth side digit missed");
			rs = -1;
		}
		else if (str[i] == ' ')
			continue;
		else
			ft_exception("Wrong format");
	}
	if (rs != -1)
		ft_exception("Wrong format: = missed");
	std::cout << "Reduced form: ";
	if (a < 0)
		std::cout << " - ";
	std::cout<< ft_abs(a) << " * X^2";
	if (b < 0)
		std::cout << " - ";
	else
		std::cout << " + ";
	std::cout<< ft_abs(b) << " * X^1";
	if (c < 0)
		std::cout << " - ";
	else
		std::cout << " + ";
	std::cout<< ft_abs(c) << " * X^0 = 0" <<std::endl;
	solve(a,b,c);
	return 0;
}

