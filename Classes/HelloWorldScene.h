//
//  HelloWorldScene.h
//  EziSocial

//  Copyright @EziByte 2013 (http://www.ezibyte.com)
//
//  Version 1.2 (Dt: 30-May-2013)
//
/***
 
 This software is provided 'as-is', without any express or implied warranty. In no event will the authors be held liable for any damages arising from the use of this software.
 
 Permission is granted to anyone to use this software for any purpose, including commercial applications, and to alter it and redistribute it freely, subject to the following restrictions:
 
 1. The origin of this software must not be misrepresented; you must not claim that you wrote the original software. If you use this software in a product, an acknowledgment in the product documentation would be appreciated but is not required.
 
 2. Altered source versions must be plainly marked as such, and must not be misrepresented as being the original software.
 
 3. This notice may not be removed or altered from any source distribution.
 
 */

#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "EziSocialDelegate.h"
#include "EziFacebookUser.h"

class HelloWorld :  public cocos2d::CCLayer,
public EziFacebookDelegate,
public EziEmailDelegate,
public EziTwitterDelegate
{
    
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    virtual void onEnterTransitionDidFinish();
    
    // there's no 'id' in cpp, so we recommand to return the exactly class pointer
    static cocos2d::CCScene* scene();
    
    // a selector callback
    void menuCloseCallback(CCObject* pSender);
    
    // implement the "static node()" method manually
    CREATE_FUNC(HelloWorld);
    
    // Facebook Delegate Methods
    virtual void fbSessionCallback(int responseCode, const char* responseMessage);
    virtual void fbUserDetailCallback(int responseCode, const char* responseMessage, EziFacebookUser *fbUser);
    virtual void fbMessageCallback(int responseCode, const char* responseMessage);
    virtual void fbPageLikeCallback(int responseCode, const char* responseMessage);
    
    virtual void fbUserPhotoCallback(const char *userPhotoPath);
    
    virtual void fbSendRequestCallback(int responseCode, const char* responseMessage, cocos2d::CCArray* friendsGotRequests);
    virtual void fbPostPhotoCallback(int responseCode, const char* responseMessage);
    
    virtual void fbIncomingRequestCallback(int responseCode, const char* responseMessage, int totalIncomingRequests);
    
    // EMail Delegate
    virtual void mailCallback(int responseCode);
    
    // Twitter Callback
    virtual void twitterCallback(int responseCode);
    
    
private:
    
    const char* profileID;
    
    float SCREEN_WIDTH;
    float SCREEN_HEIGHT;
    
    float SCALE_FACTOR;
    float GAP;
    
    
    cocos2d::CCLabelTTF* pendingRequestCount;
    
    cocos2d::CCArray* _highScores;
    cocos2d::CCArray* _highScorePlayerNames;
    
    cocos2d::CCLayerColor* _previousLayer;
    cocos2d::CCLayerColor* _currentLayer;
    
    cocos2d::CCLayerColor* _loginLayer;
    cocos2d::CCLayerColor* _userDetailsLayer;
    cocos2d::CCLayerColor* _facebookActionLayer;
    cocos2d::CCLayerColor* _highScoreLayer;
    
    cocos2d::CCLabelTTF* mName;
    cocos2d::CCLabelTTF* mUsername;
    cocos2d::CCLabelTTF* mGender;
    cocos2d::CCLabelTTF* mHometown;
    cocos2d::CCLabelTTF* mPresentLocation;
    cocos2d::CCLabelTTF* mProfileID;
    cocos2d::CCLabelTTF* mFirstName;
    cocos2d::CCLabelTTF* mLastName;
    cocos2d::CCLabelTTF* mAccessToken;
    
    cocos2d::CCMenu* mFBActionMenu;
    
    cocos2d::CCSprite *mBallSprite;
    
    EziFacebookUser* mCurrentFacebookUser;
    
    
    // Preparing Pages
    void prepareLoginPage();
    void prepareUserDetailPage();
    void prepareFacebookActionPage();
    void prepareHighScorePage();
    void prepareScene();
    
    // Showing Pages
    void showLayer(cocos2d::CCLayerColor* layerToShow);
    void showLoginPage();
    void showUserDetailPage();
    void showFacebookActionPage();
    void showTwitterActionPage();
    void showHighScorePage(cocos2d::CCArray* highScoreList);
    void showRequestList();
    
    // Facebook Action Items
    void loginViaFacebook();
    void logoutFromFacebook();
    void postMessageOnFacebookWall();
    void autoPostMessageOnFacebookWall();
    void getListOfFriendsUsingThisApp();
    void checkIfUserLikeMyFacebookPage();
    void fetchFBUserDetails();
    void postScore();
    void getHighScores();
    void openFacebookPage();
    void getUserPhoto();
    
    void postPhoto();
    
    // Facebook Requests
    void sendGiftsToFriends();
    void challengeFriends();
    void inviteFriends();
    
    void checkSessionStatus();
    
    // Twitter Action Items
    void loginViaTwitter();
    void tweetMessage();
    void logoutFromTwitter();
    void checkIfUserFollowingMyTwitterID();
    
    // Sending Email
    void sendEmail();
    
    // Network Status
    void checkNetworkStatus();
    
    // Helper Methods
    void placeLabelInRow(cocos2d::CCLabelTTF* topLabel,
                         cocos2d::CCLabelTTF* labelToPlace);
    
};
#endif // __HELLOWORLD_SCENE_H__
