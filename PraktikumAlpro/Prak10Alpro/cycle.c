#include "cycle.h"
#include <stdlib.h>


Address findCycleEntryPoint(List l) {
    Address slow = l;
    Address fast = l;

    while (fast != NULL && NEXT(fast) != NULL) {
        slow = NEXT(slow);
        fast = NEXT(NEXT(fast));
        if (slow == fast) {
            break;
        }
    }

    if (fast == NULL || NEXT(fast) == NULL) {
        return NULL;
    }

    slow = l;
    while (slow != fast) {
        slow = NEXT(slow);
        fast = NEXT(fast);
    }

    return slow;
}
