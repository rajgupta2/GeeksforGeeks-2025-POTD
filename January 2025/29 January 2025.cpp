/*
Implement Pow
Implement the function power(b, e), which calculates b raised to the power of e (i.e. be).
*/
class Solution
{
public:
    double power(double b, int e)
    {
        int E = e;
        double ans = 1;
        if (e == 0)
            return ans;
        if (b == 0 || b == 1)
            return b;

        if (e < 0)
            return 1 / power(b, -e);

        double sign;
        if (b > 0)
            sign = 1;
        else
            sign = -1;
        b = sign * b;

        do
        {
            if (e % 2 == 1)
            {
                ans *= b;
                e--;
            }
            else
            {
                b = b * b;
                e /= 2;
            }
        } while (e > 0);
        if (E % 2 == 0)
            return ans;
        return sign * ans;
    }
};