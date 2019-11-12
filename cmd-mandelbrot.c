#include <stdio.h>
#define ITERATION 100

int mb(register float real, register float imag);
int circleTest(register float a, register float b);

int main() {

	register float pd = 0.03; //display pixel density (lower = more density)
	register float md = 0.005; //average calc density (lower = more density)
	register int dx = 8; //character width
	register int dy = 18; //character height
	register double sum;
	
	getchar(); //Adjust the CMD window to full screen then hit enter

	for (float i = 1.0; i >= -1.0; i -= pd) { //y
		for (float j = -1.5; j <= 1.0; j += pd*dx/dy) { //x
			sum = 0.0;
			for (register float mi = i - pd / 2; mi < i + pd / 2; mi += md) { //micro y
				for (register float mj = j - pd * dx/dy / 2; mj < j + pd * dx/dy / 2; mj += md) { //micro x
					sum += mb(mj, mi);
				}
			}
			if (sum >= pd/md * pd*dx/dy/2/md) {
				putchar('@');
			}
			else {
				putchar(' ');
			}
		}
		printf("\n");
	}

	return 0;
}

int mb(register float a, register float b) {
	register float tc;
	register float td;
	register float c = 0.0;
	register float d = 0.0;

	for (register int i = 0; i < ITERATION; i++) {
		if (!circleTest(c, d)) {
			return 0;
		}
		tc = (a + c) * (a + c) - (b + d) * (b + d);
		td = 2.0 * (a + c) * (b + d);
		c = tc;
		d = td;
	}
	return 1;
}

int circleTest(register float a, register float b) {
	if (a * a + b * b <= 4) {
		return 1;
	}
	else {
		return 0;
	}
}