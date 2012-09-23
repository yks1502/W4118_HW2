#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../android-goldfish-2.6.29/include/linux/prinfo.h" 

int main()
{
	struct prinfo *buf;
	int nr;
	int rc;

	nr = 100;
	buf = malloc(sizeof(struct prinfo) * nr);

	rc = syscall(223, buf, &nr);

//	printf("I did not crash i am a god");

	int i;
	for (i = 0; i < nr; i++) {
		struct prinfo p = buf[i];
		printf("%s,%d,%ld,%d,%d,%d,%ld\n", p.comm, p.pid, p.state,
			p.parent_pid, p.first_child_pid, p.next_sibling_pid, p.uid);
		//printf("%s\n", buf[i].comm);
	}

	printf("\nTotal entries: %d\n", rc);
	return 0;
}
