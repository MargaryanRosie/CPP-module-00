#include <iostream>

int main(int argc, char **argv)
{
    int i;
    int j;

    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    }
    else if (argc >= 2)
    {
        i = 1;

        while (argv[i])
        {
            j = 0;
            while (argv[i][j])
            {
                if (argv[i][j] >= 'a' && argv[i][j] <= 'z')
                    std::cout << char(argv[i][j] - 32);
                else
                    std::cout << char(argv[i][j]);
                j++;
            }
            if (i < argc - 1)
                std::cout << " ";
            i++;
        }
        std::cout << std::endl;
    }
    return 0;
}