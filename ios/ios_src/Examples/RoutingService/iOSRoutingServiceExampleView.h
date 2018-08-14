// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#ifndef __ExampleApp__iOSRoutingServiceExampleView__
#define __ExampleApp__iOSRoutingServiceExampleView__

#include "Types.h"
#include "IRoutingServiceExampleView.h"
#import <UIKit/UIKit.h>
#include <vector>

namespace Examples
{
class iOSRoutingServiceExampleView;
}

@interface IRoutingServiceExampleBinding : NSObject

-(instancetype) initWith:(Examples::iOSRoutingServiceExampleView*)pExample :(UIView*)pView;
-(void) toggleExpanded;
-(void) moveUp;
-(void) moveDown;
-(void) layoutViews;

@end

namespace Examples
{
class iOSRoutingServiceExampleView : public IRoutingServiceExampleView, private Eegeo::NonCopyable
{
    std::vector<IUIActionHandler*> m_toggleExpandedHandlers;
	std::vector<IUIActionHandler*> m_moveUpHandlers;
	std::vector<IUIActionHandler*> m_moveDownHandlers;
	std::vector<IUIActionHandler*> m_getRouteHandlers;
	
	IRoutingServiceExampleBinding* m_pBinding;

public:

	iOSRoutingServiceExampleView(UIView* pView);

	~iOSRoutingServiceExampleView();

    void AddToggleExpandedHandler(IUIActionHandler& handler);
    
    void RemoveToggleExpandedHandler(IUIActionHandler& handler);
    
    void ToggleExpanded();
    
	void AddMoveUpHandler(IUIActionHandler& handler);

	void RemoveMoveUpHandler(IUIActionHandler& handler);

    void MoveUp();

	void AddMoveDownHandler(IUIActionHandler& handler);

	void RemoveMoveDownHandler(IUIActionHandler& handler);

    void MoveDown();

	void AddGetRouteHandler(IUIActionHandler& handler);

	void RemoveGetRouteHandler(IUIActionHandler& handler);

    void GetRoute();

    void NotifyNeedsLayout();
};
}


#endif /* defined(__ExampleApp__iOSRoutingServiceExampleView__) */
