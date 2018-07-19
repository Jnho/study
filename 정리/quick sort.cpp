#pragma warning(disable:4996)

struct fraction
{
	int a;
	int b;
	double c;
} sol[10000], t, p;

int k = -1;
void Q(int left, int right)
{
	int q, r;
	if (left < right)
	{
		p = sol[(left + right) / 2];
		q = left - 1; r = right + 1;
		while (1)
		{

			while (sol[++q].c < p.c || sol[q].c == p.c && sol[q].b < p.b);
			while (sol[--r].c > p.c || sol[r].c == p.c && sol[r].b > p.b);

			if (q >= r) break;
			t = sol[q]; sol[q] = sol[r]; sol[r] = t;

		}

		Q(left, q - 1);
		Q(r + 1, right);
	}
}
