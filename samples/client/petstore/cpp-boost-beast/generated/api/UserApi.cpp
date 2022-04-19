/**
 * OpenAPI Petstore
 * This is a sample server Petstore server. For this sample, you can use the api key `special-key` to test the authorization filters.
 *
 * The version of the OpenAPI document: 1.0.0
 * 
 *
 * NOTE: This class is auto generated by OpenAPI-Generator 5.3.1-SNAPSHOT.
 * https://openapi-generator.tech
 * Do not edit the class manually.
 */


#include <sstream>
#include <string>
#include <map>
#include <array>
#include <algorithm>

#include <boost/lexical_cast.hpp>
#include <boost/beast/http/status.hpp>
#include <boost/format.hpp>
#include <boost/version.hpp>
#include <boost/beast/core/detail/base64.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/property_tree/json_parser.hpp>


#include "UserApi.h"


namespace org {
namespace openapitools {
namespace client {
namespace api {

using namespace org::openapitools::client::model;


namespace {
std::string selectPreferredContentType(const std::vector<std::string>& contentTypes) {
    if (contentTypes.size() == 1) {
        return contentTypes.at(0);
    }

    static const std::array<std::string, 2> preferredTypes = {"json", "xml"};
    for (const auto& preferredType: preferredTypes) {
        const auto ret = std::find_if(contentTypes.cbegin(),
                                      contentTypes.cend(),
                                      [preferredType](const std::string& str) {
                                            return str.find(preferredType) != std::string::npos;});
        if (ret != contentTypes.cend()) {
            return *ret;
        }
    }

    if (contentTypes.size() == 0) {
        return "application/json";
    }

    return contentTypes.at(0);
}

std::string base64encodeImpl(const std::string& str) {
#if BOOST_VERSION < 107100
    return boost::beast::detail::base64_encode(str);
#else
    return boost::beast::detail::base64::encode(str);
#endif
}
}

UserApiException::UserApiException(boost::beast::http::status statusCode, std::string what)
  : m_status(statusCode),
    m_what(what)
{
}

boost::beast::http::status UserApiException::getStatus() const
{
    return m_status;
}

const char* UserApiException::what() const noexcept
{
    return m_what.c_str();
}

void
UserApi::createUser(
    const std::shared_ptr<User>& user) {
    std::string requestBody;
    std::string path = m_context + "/user";
    std::map<std::string, std::string> headers;
    // Body params
    requestBody = user->toJsonString();


    static const std::vector<std::string> contentTypes{ "application/json", };
    setPreferredMediaTypeHeader(headers, "ContentType", contentTypes);

    auto statusCode = boost::beast::http::status::unknown;
    std::string responseBody;
    try {
        std::tie(statusCode, responseBody) =
            m_client->execute("POST",
                              path,
                              requestBody,
                              headers);
    }
    catch(const std::exception& e) {
        handleStdException(e);
    }
    catch(...) {
        handleUncaughtException();
    }

    if (statusCode == boost::beast::http::status(0)) {
        throw UserApiException(statusCode, "successful operation");
    }

}
void
UserApi::createUsersWithArrayInput(
    const std::vector<std::shared_ptr<User>>& user) {
    std::string requestBody;
    std::string path = m_context + "/user/createWithArray";
    std::map<std::string, std::string> headers;
    // Body params
    requestBody = createJsonStringFromModelVector(user);


    static const std::vector<std::string> contentTypes{ "application/json", };
    setPreferredMediaTypeHeader(headers, "ContentType", contentTypes);

    auto statusCode = boost::beast::http::status::unknown;
    std::string responseBody;
    try {
        std::tie(statusCode, responseBody) =
            m_client->execute("POST",
                              path,
                              requestBody,
                              headers);
    }
    catch(const std::exception& e) {
        handleStdException(e);
    }
    catch(...) {
        handleUncaughtException();
    }

    if (statusCode == boost::beast::http::status(0)) {
        throw UserApiException(statusCode, "successful operation");
    }

}
void
UserApi::createUsersWithListInput(
    const std::vector<std::shared_ptr<User>>& user) {
    std::string requestBody;
    std::string path = m_context + "/user/createWithList";
    std::map<std::string, std::string> headers;
    // Body params
    requestBody = createJsonStringFromModelVector(user);


    static const std::vector<std::string> contentTypes{ "application/json", };
    setPreferredMediaTypeHeader(headers, "ContentType", contentTypes);

    auto statusCode = boost::beast::http::status::unknown;
    std::string responseBody;
    try {
        std::tie(statusCode, responseBody) =
            m_client->execute("POST",
                              path,
                              requestBody,
                              headers);
    }
    catch(const std::exception& e) {
        handleStdException(e);
    }
    catch(...) {
        handleUncaughtException();
    }

    if (statusCode == boost::beast::http::status(0)) {
        throw UserApiException(statusCode, "successful operation");
    }

}
void
UserApi::deleteUser(
    const std::string& username) {
    std::string requestBody;
    std::string path = m_context + "/user/%1%";
    std::map<std::string, std::string> headers;
    // path params
    const auto formattedPath = boost::format(path) % username;
    path = formattedPath.str();



    auto statusCode = boost::beast::http::status::unknown;
    std::string responseBody;
    try {
        std::tie(statusCode, responseBody) =
            m_client->execute("DELETE",
                              path,
                              requestBody,
                              headers);
    }
    catch(const std::exception& e) {
        handleStdException(e);
    }
    catch(...) {
        handleUncaughtException();
    }

    if (statusCode == boost::beast::http::status(400)) {
        throw UserApiException(statusCode, "Invalid username supplied");
    }
    if (statusCode == boost::beast::http::status(404)) {
        throw UserApiException(statusCode, "User not found");
    }

}

// vendor extension
std::shared_ptr<User>
UserApi::getUserByName(
    const std::string& username) {
    std::string requestBody;
    std::string path = m_context + "/user/%1%";
    std::map<std::string, std::string> headers;
    // path params
    const auto formattedPath = boost::format(path) % username;
    path = formattedPath.str();

    static const std::vector<std::string> acceptTypes{ "application/xml","application/json", };
    setPreferredMediaTypeHeader(headers, "Accept", acceptTypes);


    auto statusCode = boost::beast::http::status::unknown;
    std::string responseBody;
    try {
        std::tie(statusCode, responseBody) =
            m_client->execute("GET",
                path,
                requestBody,
                headers);
    }
    catch(const std::exception& e) {
        handleStdException(e);
    }
    catch(...) {
        handleUncaughtException();
    }

    std::shared_ptr<User> result = std::make_shared<User>();
    if (statusCode == boost::beast::http::status(200)) {
        result->fromJsonString(responseBody);
    }
    if (statusCode == boost::beast::http::status(400)) {
        throw UserApiException(statusCode, "Invalid username supplied");
    }
    if (statusCode == boost::beast::http::status(404)) {
        throw UserApiException(statusCode, "User not found");
    }

    return result;
}


// vendor extension
void
UserApi::updateUser(
    const std::string& username, const std::shared_ptr<User>& user) {
    std::string requestBody;
    std::string path = m_context + "/user/%1%";
    std::map<std::string, std::string> headers;
    // Body params
    std::stringstream usernameStream;
    usernameStream << username;
    requestBody = usernameStream.str();
    requestBody = user->toJsonString();
    // path params
    const auto formattedPath = boost::format(path) % username;
    path = formattedPath.str();


    static const std::vector<std::string> contentTypes{ "application/json", };
    setPreferredMediaTypeHeader(headers, "ContentType", contentTypes);

    auto statusCode = boost::beast::http::status::unknown;
    std::string responseBody;
    try {
        std::tie(statusCode, responseBody) =
            m_client->execute("PUT",
                path,
                requestBody,
                headers);
    }
    catch(const std::exception& e) {
        handleStdException(e);
    }
    catch(...) {
        handleUncaughtException();
    }

    if (statusCode == boost::beast::http::status(400)) {
        throw UserApiException(statusCode, "Invalid user supplied");
    }
    if (statusCode == boost::beast::http::status(404)) {
        throw UserApiException(statusCode, "User not found");
    }

}

std::string
UserApi::loginUser(
    const std::string& username, const std::string& password) {
    std::string requestBody;
    std::string path = m_context + "/user/login";
    std::map<std::string, std::string> headers;
    // query params
    std::stringstream queryParamStream;
    queryParamStream << '?';
    queryParamStream << "username=" << username;
    queryParamStream << '&';
    queryParamStream << "password=" << password;
    
    path += queryParamStream.str();

    static const std::vector<std::string> acceptTypes{ "application/xml","application/json", };
    setPreferredMediaTypeHeader(headers, "Accept", acceptTypes);


    auto statusCode = boost::beast::http::status::unknown;
    std::string responseBody;
    try {
        std::tie(statusCode, responseBody) =
            m_client->execute("GET",
                              path,
                              requestBody,
                              headers);
    }
    catch(const std::exception& e) {
        handleStdException(e);
    }
    catch(...) {
        handleUncaughtException();
    }

    std::string result = "";
    if (statusCode == boost::beast::http::status(200)) {
        result = responseBody;
    }
    if (statusCode == boost::beast::http::status(400)) {
        throw UserApiException(statusCode, "Invalid username/password supplied");
    }

    return result;
}
void
UserApi::logoutUser(
    ) {
    std::string requestBody;
    std::string path = m_context + "/user/logout";
    std::map<std::string, std::string> headers;



    auto statusCode = boost::beast::http::status::unknown;
    std::string responseBody;
    try {
        std::tie(statusCode, responseBody) =
            m_client->execute("GET",
                              path,
                              requestBody,
                              headers);
    }
    catch(const std::exception& e) {
        handleStdException(e);
    }
    catch(...) {
        handleUncaughtException();
    }

    if (statusCode == boost::beast::http::status(0)) {
        throw UserApiException(statusCode, "successful operation");
    }

}


std::string UserApi::base64encode(const std::string& str) {
    return base64encodeImpl(str);
}

void UserApi::setPreferredMediaTypeHeader(std::map<std::string, std::string>& headers, const std::string& headerName, const std::vector<std::string>& contentTypes) {
    const std::string contentType = selectPreferredContentType(contentTypes);
    headers[headerName] = contentType;
}

void UserApi::handleStdException(const std::exception& e) {
    throw e;
}

void UserApi::handleUncaughtException() {
    throw;
}


}  // namespace org
}  // namespace openapitools
}  // namespace client
}  // namespace api
