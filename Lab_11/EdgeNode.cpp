/**
 * Name: Aleksander Eskilson
 * KUID: 2373732
 * Email: aeskilson@ku.edu
 * Desc: Class implementation for Edge Node
 */
EdgeNode::EdgeNode() {
}

EdgeNode::EdgeNode(const int weight, const int vert1, const int vert2) {
    setWeight(weight);
    setV1(vert1);
    setV2(vert2);
}

void EdgeNode::setWeight(const int weight) {
    w = weight;
}

void EdgeNode::setV1(const int vert1) {
    v1 = vert1;
}

void EdgeNode::setV2(const int vert2) {
    v2 = vert2;
}

int EdgeNode::getWeight() const {
    return w;
}

int EdgeNode::getV1() const {
    return v1;
}

int EdgeNode::getV2() const {
    return v2;
}
