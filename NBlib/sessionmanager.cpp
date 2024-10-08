#include "sessionmanager.h"

namespace Nano {
	namespace Communication {
		void SessionManager::onClosed(std::shared_ptr<Session> sender)
		{
			std::string uid = sender->getUid();
			removeSession(uid);
		}

		void SessionManager::onConnected(std::shared_ptr<Session> sender)
		{
			addSession(sender);
		}

		inline bool SessionManager::addSession(std::shared_ptr<Session> session)
		{
			if (m_sessions.size() >= m_maxSessions)
			{
				session->close();
				return false;
			}
			m_sessions.insert(std::make_pair(session->getUid(), session));
			return true;
		}

		inline void SessionManager::removeSession(std::string& uid)
		{
			m_sessions.erase(uid);
		}
	}
}