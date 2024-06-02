#include <QCoreApplication>
#include "treenode.h"

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	TreeNode *root = new TreeNode();
	TreeNode *child1 = new TreeNode(root);
	TreeNode *child2 = new TreeNode(root);
	TreeNode *child3 = new TreeNode(child1);

	root->addChild(child1);
	root->addChild(child2);
	child1->addChild(child3);

	qDebug() << "Root has " << root->getChildren().count() << " children";
	qDebug() << "Child1 has " << child1->getChildren().count() << " children";

	return a.exec();
}
