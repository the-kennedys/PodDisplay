
#include "support.h"		// support routines
#include "keys.h"		// defines key indexes for key down boolean array
#include "obj.h"		// loading and displaying wavefront OBJ derived shapes
#include "input.h"
#include "primitive.h"

#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>		// usleep

#include <kazmath.h>		// matrix manipulation routines

#include "hexapod.h"

void initDoublePod(doublepod * pod) {
    kmVec3Fill(&pod->baseLocation.node[0], 0.5, 0.866,0);
    kmVec3Fill(&pod->baseLocation.node[1], 1,0,0);
    kmVec3Fill(&pod->baseLocation.node[2], 0.5, -0.866,0);
    kmVec3Fill(&pod->baseLocation.node[3], -0.5, -0.866,0);
    kmVec3Fill(&pod->baseLocation.node[4], -1,0,0);
    kmVec3Fill(&pod->baseLocation.node[5], -0.5,0.866,0);
    kmVec3Fill(&pod->midLocation.lowerNode[0], 0.5, 0.866,-0.1);
    kmVec3Fill(&pod->midLocation.lowerNode[1], 1,0,-0.1);
    kmVec3Fill(&pod->midLocation.lowerNode[2], 0.5, -0.866,-0.1);
    kmVec3Fill(&pod->midLocation.lowerNode[3], -0.5, -0.866,-0.1);
    kmVec3Fill(&pod->midLocation.lowerNode[4], -1,0,-0.1);
    kmVec3Fill(&pod->midLocation.lowerNode[5], -0.5,0.866,-0.1);
    kmVec3Fill(&pod->midLocation.upperNode[0], 0.5, 0.866,-0.1);
    kmVec3Fill(&pod->midLocation.upperNode[1], 1,0,0.1);
    kmVec3Fill(&pod->midLocation.upperNode[2], 0.5, -0.866,0.1);
    kmVec3Fill(&pod->midLocation.upperNode[3], -0.5, -0.866,0.1);
    kmVec3Fill(&pod->midLocation.upperNode[4], -1,0,0.1);
    kmVec3Fill(&pod->midLocation.upperNode[5], -0.5,0.866,0.1);
    kmVec3Fill(&pod->topLocation.node[0], 0.5, 0.866,0);
    kmVec3Fill(&pod->topLocation.node[1], 1,0,0);
    kmVec3Fill(&pod->topLocation.node[2], 0.5, -0.866,0);
    kmVec3Fill(&pod->topLocation.node[3], -0.5, -0.866,0);
    kmVec3Fill(&pod->topLocation.node[4], -1,0,0);
    kmVec3Fill(&pod->topLocation.node[5], -0.5,0.866,0);
    kmVec3Fill(&pod->baseLocation.position, 0,0,0);
    kmVec3Fill(&pod->midLocation.position, 0,0,1);
    kmVec3Fill(&pod->topLocation.position, 0,0,2);
}

void placePlatform(doublepod * pod, kmVec3 * position, kmVec3 * rotation) {
    
}

void renderLegWithJoints(float x1, float y1, float z1, float x2, float y2, float z2);


void drawDoublePod(doublepod * pod) {
    int leg;
    kmVec3 n1, n2;
    for (leg = 0; leg< 6; leg++) {
        kmVec3Add(&n1, &pod->baseLocation.position, &pod->baseLocation.node[leg]);
        kmVec3Add(&n2, &pod->midLocation.position, &pod->midLocation.lowerNode[leg]);
        renderLegWithJoints(n1.x, n1.y, n1.z, n2.x, n2.y, n2.z);
        kmVec3Add(&n1, &pod->midLocation.position, &pod->midLocation.upperNode[leg]);
        kmVec3Add(&n2, &pod->topLocation.position, &pod->topLocation.node[leg]);
        renderLegWithJoints(n1.x, n1.y, n1.z, n2.x, n2.y, n2.z);
    }
}
