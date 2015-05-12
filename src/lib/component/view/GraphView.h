#ifndef GRAPH_VIEW_H
#define GRAPH_VIEW_H

#include <list>
#include <memory>

#include "utility/math/Vector2.h"
#include "utility/types.h"

#include "component/view/View.h"

struct DummyEdge;
struct DummyNode;
class Graph;

class GraphView : public View
{
public:
	GraphView(ViewLayout* viewLayout);
	virtual ~GraphView();

	virtual std::string getName() const;

	virtual void rebuildGraph(
		std::shared_ptr<Graph> graph, const std::vector<DummyNode>& nodes, const std::vector<DummyEdge>& edges) = 0;
	virtual void clear() = 0;
	virtual void focusToken(Id tokenId) = 0;
	virtual void defocusToken(Id tokenId) = 0;

	virtual void resizeView() = 0;

	virtual Vec2i getViewSize() const = 0;
};

#endif // GRAPH_VIEW_H
