#ifndef TREENODE_H
#define TREENODE_H

#include <QObject>
#include <QList>

class TreeNode : public QObject
{
	Q_OBJECT

public:
	explicit TreeNode(QObject *parent = nullptr)
		: QObject(parent)
	{
	}

	~TreeNode()
	{
		qDeleteAll(this->children());
	}

	void addChild(TreeNode *child)
	{
		if (child) // Check if child is not null
		{
			child->setParent(this);
		}
	}

	QList<TreeNode *> getChildren()
	{
		QList<TreeNode *> childNodes;

		for (auto child : this->children())
		{
			TreeNode *node = dynamic_cast<TreeNode *>(child);
			if (node)
			{
				childNodes.append(node);
			}
		}

		return childNodes;
	}

	TreeNode *getParent()
	{
		return dynamic_cast<TreeNode *>(this->parent());
	}
};

#endif // TREENODE_H
