// ============================================================================
// Bullet Physics 2.x — Stubs para reconstrucao do FFX.EXE
// Todas as funcoes aqui foram mapeadas via RE no binario original.
// Cobre: CollisionWorld, RigidBody, Shapes, Broadphase, Dispatcher,
//        ConstraintSolver, GjkEpa, TriangleMesh, QuantizedBvh.
// ============================================================================
#include <cstddef>
#include <cstring>

// ============================================================================
// Tipos base LinearMath (apenas estruturas de dados, sem classes completas)
// ============================================================================
#include "bullet/LinearMath/btVector3.h"
#include "bullet/LinearMath/btTransform.h"
#include "bullet/LinearMath/btAlignedObjectArray.h"
#include "bullet/LinearMath/btMatrix3x3.h"
#include "bullet/LinearMath/btQuaternion.h"
#include "bullet/LinearMath/btScalar.h"

// ============================================================================
// Forward declarations — classes abstratas do Bullet (opacas para o linker)
// Usadas apenas como ponteiros/referencias nos stubs.
// ============================================================================
struct btBroadphaseInterface;
struct btBroadphaseProxy;
struct btCollisionObject;
struct btCollisionShape;
struct btCollisionAlgorithm;
struct btConvexShape;
struct btConvexInternalShape;
struct btDispatcher;
struct btConstraintSolver;
struct btSimplexSolver;
struct btCollisionObjectWrapper;
struct btPersistentManifold;
struct btManifoldPoint;
struct btOverlappingPairCache;
struct btCollisionConfiguration;
struct btSerializer;
struct btMotionState;

// ============================================================================
// Tipos locais — structs simplificadas que espelham o layout do binario FFX
// NOTA: Nao herdam das classes reais do Bullet para evitar dependencia
// das definicoes completas das classes abstratas.
// ============================================================================

// Callback base types (opacos para link — vtable puros)
struct btCollisionWorld_RayResultCallback {
    int *vfptr;
    float m_closestHitFraction;
    btCollisionObject *m_collisionObject;
    int m_collisionFilterGroup;
    int m_collisionFilterMask;
};

struct btCollisionWorld_ContactResultCallback {
    int *vfptr;
    float m_closestHitFraction;
};

// ============================================================================
// btCollisionWorld — World-level collision queries
// ============================================================================
struct btCollisionWorld {
    int *vfptr;
    btDispatcher *dispatcher;
    btBroadphaseInterface *broadphase;
    int fieldC;

    btCollisionWorld(btDispatcher *disp, btBroadphaseInterface *bp, btCollisionConfiguration *cfg);
    virtual ~btCollisionWorld();

    void addRigidBody(void *body);
    void removeRigidBody(void *body);
    void rayTest(const btVector3 &rayFrom, const btVector3 &rayTo, btCollisionWorld_RayResultCallback &resultCallback);
    void contactPairTest(btCollisionObject *colObj0, btCollisionObject *colObj1, btCollisionWorld_ContactResultCallback &resultCallback);
    void updateSingleAabb(void *body);
    void performDiscreteCollisionDetection();
    int serialize(void *dataBuffer, int /* unused */) const;

    void contactTest(btCollisionObject *colObj, btCollisionWorld_ContactResultCallback &resultCallback);
    btDispatcher *getDispatcher() const;
    btBroadphaseInterface *getBroadphase() const;
    void debugDrawWorld();
    void updateAabbs();
};

// ============================================================================
// btDispatcher — Collision algorithm factory
// ============================================================================
struct btDispatcher {
    int *vfptr;

    btDispatcher();
    virtual ~btDispatcher();

    btCollisionAlgorithm *findAlgorithm(btCollisionObject *body0, btCollisionObject *body1);
    void *allocateCollisionAlgorithm(int size);
};

// ============================================================================
// btBroadphaseInterface — Broadphase proxy management
// ============================================================================
struct btBroadphaseInterface {
    int *vfptr;

    btBroadphaseInterface();
    virtual ~btBroadphaseInterface();

    void *createProxy(const btVector3 &aabbMin, const btVector3 &aabbMax, int shapeType, void *userPtr);
    void destroyProxy(void *proxy);
};

// ============================================================================
// btAxisSweep3 — Sweep-and-prune broadphase (Axis-Sweep 3D)
// ============================================================================
struct btAxisSweep3 {
    int *vfptr;
    int field4;
    int field8;
    int fieldC;

    btAxisSweep3(const btVector3 &worldAabbMin, const btVector3 &worldAabbMax, int maxHandles);
    virtual ~btAxisSweep3();

    void *getOverlappingPairCache() const;
    void setDefaultFilterType(int filterType);
};

// ============================================================================
// btCollisionShape — Base collision shape with AABB query
// ============================================================================
struct btCollisionShape {
    int *vfptr;
    int shapeType;
    int field8;
    int fieldC;

    btCollisionShape();
    virtual ~btCollisionShape();

    void getAabb(const btTransform &t, btVector3 &aabbMin, btVector3 &aabbOutMax) const;
    float getMargin() const;
    void setMargin(float margin);
    void setLocalScaling(const btVector3 &scaling);
    btVector3 getLocalScaling() const;
    void calculateLocalInertia(float mass, btVector3 &inertia) const;
    int getShapeType() const;
    float getAngularMotionDisc() const;
    const char *getName() const;
};

// ============================================================================
// btBoxShape — Box collision shape
// ============================================================================
struct btBoxShape : btCollisionShape {
    btVector3 m_halfExtents;
    btVector3 m_localScaling;
    float m_collisionMargin;
    btVector3 m_implicitShapeDimensions;

    btBoxShape(const btVector3 &halfExtents);
    virtual ~btBoxShape();
};

// ============================================================================
// btSphereShape — Sphere collision shape
// ============================================================================
struct btSphereShape : btCollisionShape {
    float m_radius;
    btVector3 m_localScaling;
    float m_collisionMargin;

    btSphereShape(float radius);
    virtual ~btSphereShape();

    void setUnscaledRadius(float radius);
};

// ============================================================================
// btCapsuleShape — Capsule collision shape (sphere + cylinder)
// ============================================================================
struct btCapsuleShape : btCollisionShape {
    float m_radius;
    int m_upAxis;
    float m_halfHeight;
    btVector3 m_localScaling;
    float m_collisionMargin;

    btCapsuleShape(float radius, float height);
    virtual ~btCapsuleShape();

    int getUpAxis() const;
    float getRadius() const;
    float getHalfHeight() const;
};

// ============================================================================
// btCollisionObject — Collision object state management
// ============================================================================
struct btCollisionObject {
    int *vfptr;

    void setActivationState(int state);
    int getActivationState() const;
    void setRestitution(float val);
    float getRestitution() const;
    void setFriction(float val);
    float getFriction() const;
    void setHitFraction(float val);
    float getHitFraction() const;
};

// ============================================================================
// btCompoundShape — Compound collision shape (multiple child shapes)
// ============================================================================
struct btCompoundShape : btCollisionShape {
    int numChildShapes;
    btCollisionShape **children;

    btCompoundShape();
    virtual ~btCompoundShape();

    void addChildShape(const btTransform &localTransform, btCollisionShape *shape);
    void removeChildShape(btCollisionShape *shape);
    int getNumChildShapes() const;
    btCollisionShape *getChildShape(int index) const;
    void createAabbTreeFromChildren();
    void calculatePrincipalAxisTransform(const float *masses, btTransform &principal, btVector3 &inertia) const;
    void updateChildTransform(int childIndex, const btTransform &newTransform);
    btCollisionShape *getChildList() const;
    btTransform getChildTransform(int index) const;
};

// ============================================================================
// btConvexHullShape — Convex hull from point cloud
// ============================================================================
struct btAlignedObjectArray_IntLike {
    int *data;
    int size;
    int capacity;
};

struct btConvexHullShape : btCollisionShape {
    btAlignedObjectArray_IntLike m_points;
    int m_numPoints;

    btConvexHullShape();
    virtual ~btConvexHullShape();

    void addPoint(const btVector3 &point);
    int getNumPoints() const;
};

// ============================================================================
// btRigidBody — Rigid body dynamics
// ============================================================================
struct btRigidBody : btCollisionObject {
    float mass;
    btVector3 inertia;
    float linearDamping;
    float angularDamping;

    btRigidBody(float mass, btCollisionShape *shape, const btVector3 &localInertia);
    virtual ~btRigidBody();

    void setMassProps(float mass, const btVector3 &inertia);
    void setLinearFactor(const btVector3 &linearFactor);
    void setAngularFactor(const btVector3 &angularFactor);
    void setLinearVelocity(const btVector3 &linVel);
    void setAngularVelocity(const btVector3 &angVel);
    void applyCentralForce(const btVector3 &force);
    void applyTorque(const btVector3 &torque);
    void applyCentralImpulse(const btVector3 &impulse);
    void clearForces();
    void activate(bool forceActivation);
    float getInvMass() const;
    void setDamping(float linDamping, float angDamping);
    void proceedToTransform(const btTransform &newTrans);
    void setCenterOfMassTransform(const btTransform &xform);
    btTransform getCenterOfMassTransform() const;
    void setSleepingThresholds(float linear, float angular);
    void getSleepingThresholds(float &linear, float &angular) const;
    void setCcdMotionThreshold(float threshold);
    void setCcdSweptSphereRadius(float radius);
    int calculateSerializeBufferSize() const;
};

// ============================================================================
// btConstraintSolver — Abstract constraint solver base
// ============================================================================
struct btConstraintSolver {
    int *vfptr;

    btConstraintSolver();
    virtual ~btConstraintSolver();

    float solveGroup(void *bodies, int numBodies, void *manifolds, int numManifolds,
                     void *constraints, int numConstraints, void *info, void *debugDrawer,
                     void *dispatcher, float timeStep);
};

// ============================================================================
// btSequentialImpulseConstraintSolver — PBD-style constraint solver
// ============================================================================
struct btSequentialImpulseConstraintSolver : btConstraintSolver {
    int field4;
    int field8;
    int fieldC;

    btSequentialImpulseConstraintSolver();
    virtual ~btSequentialImpulseConstraintSolver();

    float solveGroup(void *bodies, int numBodies, void *manifolds, int numManifolds,
                     void *constraints, int numConstraints, void *info, void *debugDrawer,
                     void *dispatcher, float timeStep);
    void prepareSolve(int numBodies, int numManifolds);
    void allSolved(void *solverInfo);
    float rand2(int seed) const;
    int seedRand2(int seed);
};

// ============================================================================
// btGjkEpaPenetrationDepthSolver — GJK+EPA narrow-phase PD solver
// ============================================================================
struct btGjkEpaPenetrationDepthSolver {
    int *vfptr;

    btGjkEpaPenetrationDepthSolver();
    virtual ~btGjkEpaPenetrationDepthSolver();

    int calcPenDepth(btSimplexSolver *simplexSolver, btConvexShape *shapeA, btConvexShape *shapeB,
                     const btTransform &transA, const btTransform &transB,
                     btVector3 &normal, btVector3 &pointA, btVector3 &pointB,
                     void *debugDraw, void *stackAlloc);
};

// ============================================================================
// btTriangleMesh — Triangle mesh for concave collision
// ============================================================================
struct btTriangleMesh {
    int *vfptr;
    btAlignedObjectArray_IntLike m_vertices;
    btAlignedObjectArray_IntLike m_triangles;
    int m_usesQuantizedAabbCompression;

    btTriangleMesh();
    virtual ~btTriangleMesh();

    void addTriangle(const btVector3 &v0, const btVector3 &v1, const btVector3 &v2);
    int getNumTriangles() const;
    int findOrAddVertex(const btVector3 &vertex, bool removeDuplicate);
    void addTriangleIndices(int index0, int index1, int index2);
};

// ============================================================================
// btQuantizedBvh — Quantized Bounding Volume Hierarchy
// ============================================================================
struct btQuantizedBvh {
    int *vfptr;
    int m_bvhFlags;
    int m_ownsData;
    btAlignedObjectArray_IntLike m_subTrees;
    btAlignedObjectArray_IntLike m_leafNodes;

    btQuantizedBvh();
    virtual ~btQuantizedBvh();

    void setQuantizationValues(const btVector3 &bvhAabbMin, const btVector3 &bvhAabbMax, float quantizationMargin);
    int serialize(void *dataBuffer, int /* unused */, bool /* unused */) const;
};

// ============================================================================
// btManifoldResult — Contact manifold result
// ============================================================================
struct btManifoldResult {
    int *vfptr;

    btManifoldResult();
    virtual ~btManifoldResult();
};

// ============================================================================
// btSimplexSolver — Simplex solver for GJK
// ============================================================================
struct btSimplexSolver {
    int *vfptr;

    btSimplexSolver();
    virtual ~btSimplexSolver();
};

// ============================================================================
// btGhostObject — Ghost object (atravessa sem resposta de colisao)
// ============================================================================
struct btGhostObject : btCollisionObject {
    // Stub
};

// ============================================================================
// btPairCachingGhostObject — Ghost object com cache de pares
// ============================================================================
struct btPairCachingGhostObject : btGhostObject {
    // Stub
};

// ============================================================================
// btOverlappingPairCache — Broadphase pair cache management
// ============================================================================
struct btOverlappingPairCache {
    int *vfptr;
};

// ============================================================================
// IMPLEMENTACOES
// ============================================================================

// ============================================================================
// btCollisionWorld
// ============================================================================
btCollisionWorld::btCollisionWorld(btDispatcher *disp, btBroadphaseInterface *bp, btCollisionConfiguration *cfg) {
    this->vfptr = nullptr;
    this->dispatcher = disp;
    this->broadphase = bp;
    this->fieldC = 0;
}

btCollisionWorld::~btCollisionWorld() {}

void btCollisionWorld::addRigidBody(void *body) {}

void btCollisionWorld::removeRigidBody(void *body) {}

void btCollisionWorld::rayTest(const btVector3 &rayFrom, const btVector3 &rayTo, btCollisionWorld_RayResultCallback &resultCallback) {
    resultCallback.m_closestHitFraction = 1.0f;
}

void btCollisionWorld::contactPairTest(btCollisionObject *colObj0, btCollisionObject *colObj1, btCollisionWorld_ContactResultCallback &resultCallback) {}

void btCollisionWorld::updateSingleAabb(void *body) {}

void btCollisionWorld::performDiscreteCollisionDetection() {}

int btCollisionWorld::serialize(void *dataBuffer, int /* unused param */) const {
    return 0;
}

void btCollisionWorld::contactTest(btCollisionObject *colObj, btCollisionWorld_ContactResultCallback &resultCallback) {
    resultCallback.m_closestHitFraction = 1.0f;
}

btDispatcher *btCollisionWorld::getDispatcher() const {
    return this->dispatcher;
}

btBroadphaseInterface *btCollisionWorld::getBroadphase() const {
    return this->broadphase;
}

void btCollisionWorld::debugDrawWorld() {}

void btCollisionWorld::updateAabbs() {}

// ============================================================================
// btDispatcher
// ============================================================================
btDispatcher::btDispatcher() {
    this->vfptr = nullptr;
}

btDispatcher::~btDispatcher() {}

btCollisionAlgorithm *btDispatcher::findAlgorithm(btCollisionObject *body0, btCollisionObject *body1) {
    return nullptr;
}

void *btDispatcher::allocateCollisionAlgorithm(int size) {
    return new char[static_cast<size_t>(size)];
}

// ============================================================================
// btBroadphaseInterface
// ============================================================================
btBroadphaseInterface::btBroadphaseInterface() {
    this->vfptr = nullptr;
}

btBroadphaseInterface::~btBroadphaseInterface() {}

void *btBroadphaseInterface::createProxy(const btVector3 &aabbMin, const btVector3 &aabbMax, int shapeType, void *userPtr) {
    return nullptr;
}

void btBroadphaseInterface::destroyProxy(void *proxy) {}

// ============================================================================
// btAxisSweep3
// ============================================================================
btAxisSweep3::btAxisSweep3(const btVector3 &worldAabbMin, const btVector3 &worldAabbMax, int maxHandles) {}

btAxisSweep3::~btAxisSweep3() {}

void *btAxisSweep3::getOverlappingPairCache() const {
    return nullptr;
}

void btAxisSweep3::setDefaultFilterType(int filterType) {}

// ============================================================================
// btCollisionShape
// ============================================================================
btCollisionShape::btCollisionShape() {
    this->vfptr = nullptr;
    this->shapeType = 0;
    this->field8 = 0;
}

btCollisionShape::~btCollisionShape() {}

void btCollisionShape::getAabb(const btTransform &t, btVector3 &aabbMin, btVector3 &aabbOutMax) const {
    aabbMin = btVector3(-1.0f, -1.0f, -1.0f);
    aabbOutMax = btVector3(1.0f, 1.0f, 1.0f);
}

float btCollisionShape::getMargin() const {
    return 0.04f;
}

void btCollisionShape::setMargin(float margin) {}

void btCollisionShape::setLocalScaling(const btVector3 &scaling) {}

btVector3 btCollisionShape::getLocalScaling() const {
    return btVector3(1.0f, 1.0f, 1.0f);
}

void btCollisionShape::calculateLocalInertia(float mass, btVector3 &inertia) const {
    inertia = btVector3(0.0f, 0.0f, 0.0f);
}

int btCollisionShape::getShapeType() const {
    return this->shapeType;
}

float btCollisionShape::getAngularMotionDisc() const {
    return 1.0f;
}

const char *btCollisionShape::getName() const {
    return "btCollisionShape";
}

// ============================================================================
// btBoxShape
// ============================================================================
btBoxShape::btBoxShape(const btVector3 &halfExtents) {
    this->vfptr = nullptr;
    this->shapeType = 0;
    this->field8 = 0;
    this->fieldC = 0;
    this->m_halfExtents = halfExtents;
    this->m_localScaling = btVector3(1.0f, 1.0f, 1.0f);
    this->m_collisionMargin = 0.04f;
    this->m_implicitShapeDimensions = halfExtents;
}

btBoxShape::~btBoxShape() {}

// ============================================================================
// btSphereShape
// ============================================================================
btSphereShape::btSphereShape(float radius) {
    this->vfptr = nullptr;
    this->shapeType = 0;
    this->field8 = 0;
    this->fieldC = 0;
    this->m_radius = radius;
    this->m_localScaling = btVector3(1.0f, 1.0f, 1.0f);
    this->m_collisionMargin = 0.04f;
}

btSphereShape::~btSphereShape() {}

void btSphereShape::setUnscaledRadius(float radius) {
    this->m_radius = radius;
}

// ============================================================================
// btCapsuleShape
// ============================================================================
btCapsuleShape::btCapsuleShape(float radius, float height) {
    this->vfptr = nullptr;
    this->shapeType = 0;
    this->field8 = 0;
    this->fieldC = 0;
    this->m_radius = radius;
    this->m_upAxis = 1;
    this->m_halfHeight = height * 0.5f;
    this->m_localScaling = btVector3(1.0f, 1.0f, 1.0f);
    this->m_collisionMargin = 0.04f;
}

btCapsuleShape::~btCapsuleShape() {}

int btCapsuleShape::getUpAxis() const {
    return this->m_upAxis;
}

float btCapsuleShape::getRadius() const {
    return this->m_radius;
}

float btCapsuleShape::getHalfHeight() const {
    return this->m_halfHeight;
}

// ============================================================================
// btCompoundShape
// ============================================================================
btCompoundShape::btCompoundShape() {
    this->vfptr = nullptr;
    this->shapeType = 0;
    this->field8 = 0;
    this->fieldC = 0;
    this->numChildShapes = 0;
    this->children = nullptr;
}

btCompoundShape::~btCompoundShape() {}

void btCompoundShape::addChildShape(const btTransform &localTransform, btCollisionShape *shape) {
    (void)localTransform;
    btCollisionShape **newChildren = new btCollisionShape *[
        static_cast<size_t>(this->numChildShapes) + 1];
    if (this->children) {
        memcpy(newChildren, this->children,
               static_cast<size_t>(this->numChildShapes) * sizeof(void *));
        delete[] this->children;
    }
    this->children = newChildren;
    this->children[this->numChildShapes] = shape;
    this->numChildShapes++;
}

void btCompoundShape::removeChildShape(btCollisionShape *shape) {
    for (int i = 0; i < this->numChildShapes; i++) {
        if (this->children[i] == shape) {
            for (int j = i; j < this->numChildShapes - 1; j++) {
                this->children[j] = this->children[j + 1];
            }
            this->numChildShapes--;
            break;
        }
    }
}

int btCompoundShape::getNumChildShapes() const {
    return this->numChildShapes;
}

btCollisionShape *btCompoundShape::getChildShape(int index) const {
    if (index >= 0 && index < this->numChildShapes) {
        return this->children[index];
    }
    return nullptr;
}

void btCompoundShape::createAabbTreeFromChildren() {}

void btCompoundShape::calculatePrincipalAxisTransform(const float *masses, btTransform &principal, btVector3 &inertia) const {
    principal = btTransform();
    inertia = btVector3(1.0f, 1.0f, 1.0f);
}

void btCompoundShape::updateChildTransform(int childIndex, const btTransform &newTransform) {}

btCollisionShape *btCompoundShape::getChildList() const {
    if (this->numChildShapes > 0)
        return this->children[0];
    return nullptr;
}

btTransform btCompoundShape::getChildTransform(int index) const {
    return btTransform();
}

// ============================================================================
// btConvexHullShape
// ============================================================================
btConvexHullShape::btConvexHullShape() {
    this->vfptr = nullptr;
    this->m_numPoints = 0;
    this->m_points.data = nullptr;
    this->m_points.size = 0;
    this->m_points.capacity = 0;
}

btConvexHullShape::~btConvexHullShape() {}

void btConvexHullShape::addPoint(const btVector3 &point) {
    int idx = this->m_points.size;
    if (idx >= this->m_points.capacity) {
        int newCap = (this->m_points.capacity == 0) ? 16 : (this->m_points.capacity * 2);
        int *newData = new int[static_cast<size_t>(newCap) * 3];
        if (this->m_points.data) {
            memcpy(newData, this->m_points.data, static_cast<size_t>(idx) * 3 * sizeof(int));
            delete[] this->m_points.data;
        }
        this->m_points.data = newData;
        this->m_points.capacity = newCap;
    }
    reinterpret_cast<float *>(this->m_points.data)[idx * 3 + 0] = point.x();
    reinterpret_cast<float *>(this->m_points.data)[idx * 3 + 1] = point.y();
    reinterpret_cast<float *>(this->m_points.data)[idx * 3 + 2] = point.z();
    this->m_points.size++;
    this->m_numPoints = this->m_points.size;
}

int btConvexHullShape::getNumPoints() const {
    return this->m_numPoints;
}

// ============================================================================
// btRigidBody
// ============================================================================
btRigidBody::btRigidBody(float mass, btCollisionShape *shape, const btVector3 &localInertia) {
    this->vfptr = nullptr;
    this->mass = mass;
    this->inertia = localInertia;
    this->linearDamping = 0.0f;
    this->angularDamping = 0.0f;
}

btRigidBody::~btRigidBody() {}

void btRigidBody::setMassProps(float mass_, const btVector3 &inertia_) {
    this->mass = mass_;
    this->inertia = inertia_;
}

void btRigidBody::setLinearFactor(const btVector3 &linearFactor) {}

void btRigidBody::setAngularFactor(const btVector3 &angularFactor) {}

void btRigidBody::setLinearVelocity(const btVector3 &linVel) {}

void btRigidBody::setAngularVelocity(const btVector3 &angVel) {}

void btRigidBody::applyCentralForce(const btVector3 &force) {}

void btRigidBody::applyTorque(const btVector3 &torque) {}

void btRigidBody::applyCentralImpulse(const btVector3 &impulse) {}

void btRigidBody::clearForces() {}

void btRigidBody::activate(bool forceActivation) {}

float btRigidBody::getInvMass() const {
    return (this->mass > 0.0f) ? (1.0f / this->mass) : 0.0f;
}

void btRigidBody::setDamping(float linDamping, float angDamping) {
    this->linearDamping = linDamping;
    this->angularDamping = angDamping;
}

void btRigidBody::proceedToTransform(const btTransform &newTrans) {}

void btRigidBody::setCenterOfMassTransform(const btTransform &xform) {}

btTransform btRigidBody::getCenterOfMassTransform() const {
    return btTransform();
}

void btRigidBody::setSleepingThresholds(float linear, float angular) {}

void btRigidBody::getSleepingThresholds(float &linear, float &angular) const {
    linear = 0.8f;
    angular = 1.0f;
}

void btRigidBody::setCcdMotionThreshold(float threshold) {}

void btRigidBody::setCcdSweptSphereRadius(float radius) {}

int btRigidBody::calculateSerializeBufferSize() const {
    return 0;
}

// ============================================================================
// btCollisionObject
// ============================================================================
void btCollisionObject::setActivationState(int state) {}

int btCollisionObject::getActivationState() const {
    return 1;
}

void btCollisionObject::setRestitution(float val) {}

float btCollisionObject::getRestitution() const {
    return 0.0f;
}

void btCollisionObject::setFriction(float val) {}

float btCollisionObject::getFriction() const {
    return 0.5f;
}

void btCollisionObject::setHitFraction(float val) {}

float btCollisionObject::getHitFraction() const {
    return 1.0f;
}

// ============================================================================
// btConstraintSolver
// ============================================================================
btConstraintSolver::btConstraintSolver() {
    this->vfptr = nullptr;
}

btConstraintSolver::~btConstraintSolver() {}

float btConstraintSolver::solveGroup(void *bodies, int numBodies, void *manifolds, int numManifolds,
                                     void *constraints, int numConstraints, void *info, void *debugDrawer,
                                     void *dispatcher, float timeStep) {
    return 0.0f;
}

// ============================================================================
// btSequentialImpulseConstraintSolver
// ============================================================================
btSequentialImpulseConstraintSolver::btSequentialImpulseConstraintSolver() {
    this->vfptr = nullptr;
}

btSequentialImpulseConstraintSolver::~btSequentialImpulseConstraintSolver() {}

float btSequentialImpulseConstraintSolver::solveGroup(void *bodies, int numBodies, void *manifolds, int numManifolds,
                                                      void *constraints, int numConstraints, void *info, void *debugDrawer,
                                                      void *dispatcher, float timeStep) {
    return 0.0f;
}

void btSequentialImpulseConstraintSolver::prepareSolve(int numBodies, int numManifolds) {}

void btSequentialImpulseConstraintSolver::allSolved(void *solverInfo) {}

float btSequentialImpulseConstraintSolver::rand2(int seed) const {
    return 0.0f;
}

int btSequentialImpulseConstraintSolver::seedRand2(int seed) {
    return seed;
}

// ============================================================================
// btGjkEpaPenetrationDepthSolver
// ============================================================================
btGjkEpaPenetrationDepthSolver::btGjkEpaPenetrationDepthSolver() {
    this->vfptr = nullptr;
}

btGjkEpaPenetrationDepthSolver::~btGjkEpaPenetrationDepthSolver() {}

int btGjkEpaPenetrationDepthSolver::calcPenDepth(
    btSimplexSolver *simplexSolver, btConvexShape *shapeA, btConvexShape *shapeB,
    const btTransform &transA, const btTransform &transB,
    btVector3 &normal, btVector3 &pointA, btVector3 &pointB,
    void *debugDraw, void *stackAlloc) {
    (void)simplexSolver;
    (void)shapeA;
    (void)shapeB;
    (void)transA;
    (void)transB;
    (void)debugDraw;
    (void)stackAlloc;
    normal = btVector3(0.0f, 1.0f, 0.0f);
    pointA = btVector3(0.0f, 0.0f, 0.0f);
    pointB = btVector3(0.0f, 0.0f, 0.0f);
    return 0;
}

// ============================================================================
// btTriangleMesh
// ============================================================================
btTriangleMesh::btTriangleMesh() {
    this->vfptr = nullptr;
    this->m_usesQuantizedAabbCompression = 1;
}

btTriangleMesh::~btTriangleMesh() {}

void btTriangleMesh::addTriangle(const btVector3 &v0, const btVector3 &v1, const btVector3 &v2) {}

int btTriangleMesh::getNumTriangles() const {
    return this->m_triangles.size;
}

int btTriangleMesh::findOrAddVertex(const btVector3 &vertex, bool removeDuplicate) {
    return 0;
}

void btTriangleMesh::addTriangleIndices(int index0, int index1, int index2) {}

// ============================================================================
// btQuantizedBvh
// ============================================================================
btQuantizedBvh::btQuantizedBvh() {
    this->vfptr = nullptr;
}

btQuantizedBvh::~btQuantizedBvh() {}

void btQuantizedBvh::setQuantizationValues(const btVector3 &bvhAabbMin, const btVector3 &bvhAabbMax, float quantizationMargin) {}

int btQuantizedBvh::serialize(void *dataBuffer, int /* unused param */, bool /* unused param */) const {
    return 0;
}

// ============================================================================
// btManifoldResult
// ============================================================================
btManifoldResult::btManifoldResult() {
    this->vfptr = nullptr;
}

btManifoldResult::~btManifoldResult() {}

// ============================================================================
// btSimplexSolver
// ============================================================================
btSimplexSolver::btSimplexSolver() {
    this->vfptr = nullptr;
}

btSimplexSolver::~btSimplexSolver() {}

// ============================================================================
// Funcoes livres — FFX-specific extensions (nao existem no Bullet SDK oficial)
// ============================================================================

// btGhostObject_constructor
void btGhostObject_constructor(void *self) { }

// btGhostObject_destructor
void btGhostObject_destructor(void *self) { }

// btPairCachingGhostObject_constructor
void btPairCachingGhostObject_constructor(void *self) { }

// btPairCachingGhostObject_destructor
void btPairCachingGhostObject_destructor(void *self) { }

// btCollisionWorld_rayTestSingle
void btCollisionWorld_rayTestSingle(void *self) { }

// btCollisionWorld_objectQuerySingle
void btCollisionWorld_objectQuerySingle(void *self) { }

// btCollisionWorld_serialize
void btCollisionWorld_serialize(void *self) { }

// btOverlappingPairCache_processAllOverlappingPairs
void btOverlappingPairCache_processAllOverlappingPairs(void *self) { }

// btOverlappingPairCache_cleanProxyFromPairs
void btOverlappingPairCache_cleanProxyFromPairs(void *self) { }

// btOverlappingPairCache_removeOverlappingPairsContainingProxy
void btOverlappingPairCache_removeOverlappingPairsContainingProxy(void *self) { }

// ============================================================================
// EXPANSION: 6 stubs novos (2026-07-05)
// ============================================================================

// btCollisionWorld_updateSingleAabb (0x9xxxxx) — Atualiza AABB de um body no broadphase
void btCollisionWorld_updateSingleAabb(void *self) { }

// btCollisionWorld_performDiscreteCollisionDetection (0x9xxxxx) — Executa deteccao de colisao discreta
void btCollisionWorld_performDiscreteCollisionDetection(void *self) { }

// btCollisionObject_setWorldTransform (0x9xxxxx) — Define a transformacao mundial do objeto
void btCollisionObject_setWorldTransform(void *self) { }

// btCollisionObject_getWorldTransform (0x9xxxxx) — Retorna a transformacao mundial do objeto
void btCollisionObject_getWorldTransform(void *self) { }

// btRigidBody_integrateVelocities (0x9xxxxx) — Integra velocidades linear e angular
void btRigidBody_integrateVelocities(void *self) { }

// btRigidBody_clearForces (0x9xxxxx) — Zera acumuladores de forca
void btRigidBody_clearForces(void *self) { }
