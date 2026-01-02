#include<bits/stdc++.h>
using namespace std;

// abstract observer interface
class ISubscriber {
public:
    virtual void update() = 0;
    virtual ~ISubscriber() {}
};

// abstract observable interface
class IChannel {
public:
    virtual void subscribe(ISubscriber* subscriber) = 0;
    virtual void unsubscribe(ISubscriber* subscriber) = 0;
    virtual void notifySubscribers() = 0;
    virtual ~IChannel() {}
};

// concrete observable class
class YouTubeChannel : public IChannel {
private:
    vector<ISubscriber*> subscribers;
    string channelName;
    string latestVideo;
public:
    YouTubeChannel(const string& channelName) {
        this->channelName = channelName;
    }

    // add a subscriber
    void subscribe(ISubscriber* subscriber) override {
        if (find(subscribers.begin(), subscribers.end(), subscriber) == subscribers.end()) {
            subscribers.push_back(subscriber);
        }
    }

    // remove a subscriber
    void unsubscribe(ISubscriber* subscriber) override {
        auto it = find(subscribers.begin(), subscribers.end(), subscriber);
        if (it != subscribers.end()) {
            subscribers.erase(it);
        }
    }

    // notify all subscribers
    void notifySubscribers() override {
        for (ISubscriber* subscriber : subscribers) {
            subscriber->update();
        }
    }

    // upload a new video and notify all subscribers
    void uploadVideo(const string& videoTitle) {
        latestVideo = videoTitle;
        cout << "Channel: " << channelName << " uploaded a new video: " << latestVideo << endl;
        notifySubscribers();
    }

    string getLatestVideo() const {
        return "\nCheck out the latest video: " + latestVideo + "\n";
    }
};

// concrete observer class
class Subscriber : public ISubscriber {
private:
    string name;
    YouTubeChannel* channel;
public:
    Subscriber(const string& name, YouTubeChannel* channel) {
        this->name = name;
        this->channel = channel;
    }

    // callback method to receive updates
    void update() override {
        cout << "Subscriber: " << name << " received update from channel." << channel-> getLatestVideo() << "\n";
    }
};

int main() {
    // create a YouTube channel 
    YouTubeChannel* channel = new YouTubeChannel("Segmentation Fault");

    Subscriber* tahsin = new Subscriber("Tahsin", channel);
    Subscriber* anik = new Subscriber("Anik", channel);
    Subscriber* niloy = new Subscriber("Niloy", channel);

    // subscribers subscribe to the channel
    channel->subscribe(tahsin);
    channel->subscribe(anik);
    channel->subscribe(niloy);

    // channel uploads a new video
    channel->uploadVideo("ICPC theke taka kmne ushol korte hoy?");

    // subscriber 'Anik' unsubscribes from the channel
    channel->unsubscribe(anik);

    // channel uploads another video
    channel->uploadVideo("C++ STL Tutorial for Beginners");
    return 0;
}