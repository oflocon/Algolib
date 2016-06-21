#define N 100010
#define A 1000010
#define BLOCK 555  // ~sqrt(N)

int cnt[A], a[N], ans[N], answer = 0, was_three = 0;

struct node {
  int L, R, i;
} q[N];

bool cmp(node x, node y) {
  if (x.L / BLOCK != y.L / BLOCK) {
    // different blocks, so sort by block.
    return x.L / BLOCK < y.L / BLOCK;
  }
  // same block, so sort by R value
  return x.R < y.R;
}

void add(int position) {
  const int x = a[position];
  cnt[x]++;
  int coef = x % 3;
  if (!coef) {
    was_three ^= 1;
  } else {
    answer = answer * coef % 3;
  }
}

void remove(int position) {
  const int x = a[position];
  cnt[x]--;
  int coef = x % 3;
  if (coef) {
    answer = answer * coef % 3;
  } else {
    was_three ^= 1;
  }
}

int main() {


  memset(cnt, 0, sizeof(cnt));

  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);

  for (int i = 0; i < m; i++) {
    scanf("%d%d", &q[i].L, &q[i].R);
    q[i].L--;
    q[i].R--;
    q[i].i = i;
  }

  sort(q, q + m, cmp);

  answer = 1;
  was_three = 0;

  int currentL = 0, currentR = 0;
  for (int i = 0; i < m; i++) {
    int L = q[i].L, R = q[i].R;

    if (L > R) {
      ans[q[i].i] = 0;
      continue;
    }

    while (currentL < L) {
      remove(currentL);
      currentL++;
    }
    while (currentL > L) {
      add(currentL - 1);
      currentL--;
    }
    while (currentR <= R) {
      add(currentR);
      currentR++;
    }
    while (currentR > R + 1) {
      remove(currentR - 1);
      currentR--;
    }
    ans[q[i].i] = answer * (1 - was_three);
  }

  for (int i = 0; i < m; i++) printf("%d\n", ans[i]);
