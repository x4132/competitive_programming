#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;

    cin >> T;

    for (int cases = 0; cases < T; cases++)
    {
        int N, K;
        cin >> N >> K;

        string cowstr;
        cin >> cowstr;

        string output = "";
        int padsUsed = 0;

        int fg = -100001, fh = -100001;
        int pg = -100001, ph = -100001;

        for (int i = 0; i < N; i++)
        {
            char cur = cowstr[i];

            if (cur == 'G' && fg == -100001 && std::abs(pg - i) > K)
            {
                fg = i;
            }
            else if (cur == 'H' && fh == -100001 && std::abs(ph - i) > K)
            {
                fh = i;
            }

            if (i - fg == K)
            {
                padsUsed++;
                output += "G";

                fg = -100001;
                pg = i;
            }
            else if (i - fh == K)
            {
                padsUsed++;
                output += "H";

                fh = -100001;
                ph = i;
            }
            else
            {
                output += ".";
            }
        }

        if (fh != -100001 && abs(fh - ph) > K)
        {
            bool found = false;
            padsUsed++;
            for (int i = fh; i < fh + K; i++)
            {
                if (output[i] == '.')
                {
                    found = true;
                    output[i] = 'H';
                    break;
                }
            }

            if (!found)
            {
                for (int i = fh - 1; i >= fh - K && i >= 0; i++)
                {
                    if (output[i] == '.')
                    {
                        output[i] = 'H';
                        break;
                    }
                }
            }
        }

        if (fg != -100001 && abs(fg - pg) > K)
        {
            bool found = false;
            padsUsed++;
            for (int i = fg; i < fg + K; i++)
            {
                if (output[i] == '.')
                {
                    found = true;
                    output[i] = 'G';
                    break;
                }
            }

            if (!found)
            {
                for (int i = fg - 1; i >= fg - K && i >= 0; i++)
                {
                    if (output[i] == '.')
                    {
                        output[i] = 'G';
                        break;
                    }
                }
            }
        }

        cout << padsUsed << "\n"
             << output << endl;
    }
}