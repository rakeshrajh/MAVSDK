// WARNING: THIS FILE IS AUTOGENERATED! As such, it should not be edited.
// Edits need to be made to the proto files
// (see https://github.com/mavlink/MAVSDK-Proto/blob/master/protos/mission/mission.proto)

#include "mission/mission.grpc.pb.h"
#include "plugins/mission/mission.h"

#include "log.h"
#include <atomic>
#include <future>
#include <memory>
#include <vector>

namespace mavsdk {
namespace backend {

template<typename Mission = Mission>
class MissionServiceImpl final : public rpc::mission::MissionService::Service {
public:
    MissionServiceImpl(Mission& mission) : _mission(mission) {}

    template<typename ResponseType>
    void fillResponseWithResult(ResponseType* response, mavsdk::Mission::Result& result) const
    {
        auto rpc_result = translateToRpcResult(result);

        auto* rpc_mission_result = new rpc::mission::MissionResult();
        rpc_mission_result->set_result(rpc_result);
        rpc_mission_result->set_result_str(mavsdk::Mission::result_str(result));

        response->set_allocated_mission_result(rpc_mission_result);
    }

    static rpc::mission::MissionItem::CameraAction
    translateToRpcCameraAction(const mavsdk::Mission::CameraAction& camera_action)
    {
        switch (camera_action) {
            default:
                LogErr() << "Unknown camera_action enum value: " << static_cast<int>(camera_action);
            // FALLTHROUGH
            case mavsdk::Mission::CameraAction::None:
                return rpc::mission::MissionItem_CameraAction_CAMERA_ACTION_NONE;
            case mavsdk::Mission::CameraAction::TakePhoto:
                return rpc::mission::MissionItem_CameraAction_CAMERA_ACTION_TAKE_PHOTO;
            case mavsdk::Mission::CameraAction::StartPhotoInterval:
                return rpc::mission::MissionItem_CameraAction_CAMERA_ACTION_START_PHOTO_INTERVAL;
            case mavsdk::Mission::CameraAction::StopPhotoInterval:
                return rpc::mission::MissionItem_CameraAction_CAMERA_ACTION_STOP_PHOTO_INTERVAL;
            case mavsdk::Mission::CameraAction::StartVideo:
                return rpc::mission::MissionItem_CameraAction_CAMERA_ACTION_START_VIDEO;
            case mavsdk::Mission::CameraAction::StopVideo:
                return rpc::mission::MissionItem_CameraAction_CAMERA_ACTION_STOP_VIDEO;
        }
    }

    static mavsdk::Mission::CameraAction
    translateFromRpcCameraAction(const rpc::mission::MissionItem::CameraAction camera_action)
    {
        switch (camera_action) {
            default:
                LogErr() << "Unknown camera_action enum value: " << static_cast<int>(camera_action);
            // FALLTHROUGH
            case rpc::mission::MissionItem_CameraAction_CAMERA_ACTION_NONE:
                return mavsdk::Mission::CameraAction::None;
        }
    }

    static std::unique_ptr<rpc::mission::MissionItem>
    translateToRpcMissionItem(const mavsdk::Mission::MissionItem& mission_item)
    {
        std::unique_ptr<rpc::mission::MissionItem> rpc_obj(new rpc::mission::MissionItem());

        rpc_obj->set_latitude_deg(mission_item.latitude_deg);

        rpc_obj->set_longitude_deg(mission_item.longitude_deg);

        rpc_obj->set_relative_altitude_m(mission_item.relative_altitude_m);

        rpc_obj->set_speed_m_s(mission_item.speed_m_s);

        rpc_obj->set_is_fly_through(mission_item.is_fly_through);

        rpc_obj->set_gimbal_pitch_deg(mission_item.gimbal_pitch_deg);

        rpc_obj->set_gimbal_yaw_deg(mission_item.gimbal_yaw_deg);

        rpc_obj->set_camera_action(translateToRpcCameraAction(mission_item.camera_action));

        rpc_obj->set_loiter_time_s(mission_item.loiter_time_s);

        rpc_obj->set_camera_photo_interval_s(mission_item.camera_photo_interval_s);

        return rpc_obj;
    }

    static mavsdk::Mission::MissionItem
    translateFromRpcMissionItem(const rpc::mission::MissionItem& mission_item)
    {
        mavsdk::Mission::MissionItem obj;

        obj.latitude_deg = mission_item.latitude_deg();

        obj.longitude_deg = mission_item.longitude_deg();

        obj.relative_altitude_m = mission_item.relative_altitude_m();

        obj.speed_m_s = mission_item.speed_m_s();

        obj.is_fly_through = mission_item.is_fly_through();

        obj.gimbal_pitch_deg = mission_item.gimbal_pitch_deg();

        obj.gimbal_yaw_deg = mission_item.gimbal_yaw_deg();

        obj.camera_action = translateFromRpcCameraAction(mission_item.camera_action());

        obj.loiter_time_s = mission_item.loiter_time_s();

        obj.camera_photo_interval_s = mission_item.camera_photo_interval_s();

        return obj;
    }

    static std::unique_ptr<rpc::mission::MissionPlan>
    translateToRpcMissionPlan(const mavsdk::Mission::MissionPlan& mission_plan)
    {
        std::unique_ptr<rpc::mission::MissionPlan> rpc_obj(new rpc::mission::MissionPlan());

        for (const auto& elem : mission_plan.mission_items) {
            auto* ptr = rpc_obj->add_mission_items();
            ptr->CopyFrom(*translateToRpcMissionItem(elem).release());
        }

        return rpc_obj;
    }

    static mavsdk::Mission::MissionPlan
    translateFromRpcMissionPlan(const rpc::mission::MissionPlan& mission_plan)
    {
        mavsdk::Mission::MissionPlan obj;

        for (const auto& elem : mission_plan.mission_items()) {
            obj.mission_items.push_back(translateFromRpcMissionItem(elem));
        }

        return obj;
    }

    static std::unique_ptr<rpc::mission::MissionProgress>
    translateToRpcMissionProgress(const mavsdk::Mission::MissionProgress& mission_progress)
    {
        std::unique_ptr<rpc::mission::MissionProgress> rpc_obj(new rpc::mission::MissionProgress());

        rpc_obj->set_current(mission_progress.current);

        rpc_obj->set_total(mission_progress.total);

        return rpc_obj;
    }

    static mavsdk::Mission::MissionProgress
    translateFromRpcMissionProgress(const rpc::mission::MissionProgress& mission_progress)
    {
        mavsdk::Mission::MissionProgress obj;

        obj.current = mission_progress.current();

        obj.total = mission_progress.total();

        return obj;
    }

    static rpc::mission::MissionResult::Result
    translateToRpcResult(const mavsdk::Mission::Result& result)
    {
        switch (result) {
            default:
                LogErr() << "Unknown result enum value: " << static_cast<int>(result);
            // FALLTHROUGH
            case mavsdk::Mission::Result::Unknown:
                return rpc::mission::MissionResult_Result_RESULT_UNKNOWN;
            case mavsdk::Mission::Result::Success:
                return rpc::mission::MissionResult_Result_RESULT_SUCCESS;
            case mavsdk::Mission::Result::Error:
                return rpc::mission::MissionResult_Result_RESULT_ERROR;
            case mavsdk::Mission::Result::TooManyMissionItems:
                return rpc::mission::MissionResult_Result_RESULT_TOO_MANY_MISSION_ITEMS;
            case mavsdk::Mission::Result::Busy:
                return rpc::mission::MissionResult_Result_RESULT_BUSY;
            case mavsdk::Mission::Result::Timeout:
                return rpc::mission::MissionResult_Result_RESULT_TIMEOUT;
            case mavsdk::Mission::Result::InvalidArgument:
                return rpc::mission::MissionResult_Result_RESULT_INVALID_ARGUMENT;
            case mavsdk::Mission::Result::Unsupported:
                return rpc::mission::MissionResult_Result_RESULT_UNSUPPORTED;
            case mavsdk::Mission::Result::NoMissionAvailable:
                return rpc::mission::MissionResult_Result_RESULT_NO_MISSION_AVAILABLE;
            case mavsdk::Mission::Result::FailedToOpenQgcPlan:
                return rpc::mission::MissionResult_Result_RESULT_FAILED_TO_OPEN_QGC_PLAN;
            case mavsdk::Mission::Result::FailedToParseQgcPlan:
                return rpc::mission::MissionResult_Result_RESULT_FAILED_TO_PARSE_QGC_PLAN;
            case mavsdk::Mission::Result::UnsupportedMissionCmd:
                return rpc::mission::MissionResult_Result_RESULT_UNSUPPORTED_MISSION_CMD;
            case mavsdk::Mission::Result::TransferCancelled:
                return rpc::mission::MissionResult_Result_RESULT_TRANSFER_CANCELLED;
        }
    }

    static mavsdk::Mission::Result
    translateFromRpcResult(const rpc::mission::MissionResult::Result result)
    {
        switch (result) {
            default:
                LogErr() << "Unknown result enum value: " << static_cast<int>(result);
            // FALLTHROUGH
            case rpc::mission::MissionResult_Result_RESULT_UNKNOWN:
                return mavsdk::Mission::Result::Unknown;
        }
    }

    grpc::Status UploadMission(
        grpc::ServerContext* /* context */,
        const rpc::mission::UploadMissionRequest* request,
        rpc::mission::UploadMissionResponse* response) override
    {
        if (request == nullptr) {
            LogWarn() << "UploadMission sent with a null request! Ignoring...";
            return grpc::Status::OK;
        }

        auto result = _mission.upload_mission(translateFromRpcMissionPlan(request->mission_plan()));

        if (response != nullptr) {
            fillResponseWithResult(response, result);
        }

        return grpc::Status::OK;
    }

    grpc::Status CancelMissionUpload(
        grpc::ServerContext* /* context */,
        const rpc::mission::CancelMissionUploadRequest* /* request */,
        rpc::mission::CancelMissionUploadResponse* response) override
    {
        auto result = _mission.cancel_mission_upload();

        if (response != nullptr) {
            fillResponseWithResult(response, result);
        }

        return grpc::Status::OK;
    }

    grpc::Status DownloadMission(
        grpc::ServerContext* /* context */,
        const rpc::mission::DownloadMissionRequest* /* request */,
        rpc::mission::DownloadMissionResponse* response) override
    {
        auto result_pair = _mission.download_mission();

        if (response != nullptr) {
            fillResponseWithResult(response, result_pair.first);
            response->set_allocated_mission_plan(
                translateToRpcMissionPlan(result_pair.second).release());
        }

        return grpc::Status::OK;
    }

    grpc::Status CancelMissionDownload(
        grpc::ServerContext* /* context */,
        const rpc::mission::CancelMissionDownloadRequest* /* request */,
        rpc::mission::CancelMissionDownloadResponse* response) override
    {
        auto result = _mission.cancel_mission_download();

        if (response != nullptr) {
            fillResponseWithResult(response, result);
        }

        return grpc::Status::OK;
    }

    grpc::Status StartMission(
        grpc::ServerContext* /* context */,
        const rpc::mission::StartMissionRequest* /* request */,
        rpc::mission::StartMissionResponse* response) override
    {
        auto result = _mission.start_mission();

        if (response != nullptr) {
            fillResponseWithResult(response, result);
        }

        return grpc::Status::OK;
    }

    grpc::Status PauseMission(
        grpc::ServerContext* /* context */,
        const rpc::mission::PauseMissionRequest* /* request */,
        rpc::mission::PauseMissionResponse* response) override
    {
        auto result = _mission.pause_mission();

        if (response != nullptr) {
            fillResponseWithResult(response, result);
        }

        return grpc::Status::OK;
    }

    grpc::Status ClearMission(
        grpc::ServerContext* /* context */,
        const rpc::mission::ClearMissionRequest* /* request */,
        rpc::mission::ClearMissionResponse* response) override
    {
        auto result = _mission.clear_mission();

        if (response != nullptr) {
            fillResponseWithResult(response, result);
        }

        return grpc::Status::OK;
    }

    grpc::Status SetCurrentMissionItem(
        grpc::ServerContext* /* context */,
        const rpc::mission::SetCurrentMissionItemRequest* request,
        rpc::mission::SetCurrentMissionItemResponse* response) override
    {
        if (request == nullptr) {
            LogWarn() << "SetCurrentMissionItem sent with a null request! Ignoring...";
            return grpc::Status::OK;
        }

        auto result = _mission.set_current_mission_item(request->index());

        if (response != nullptr) {
            fillResponseWithResult(response, result);
        }

        return grpc::Status::OK;
    }

    grpc::Status IsMissionFinished(
        grpc::ServerContext* /* context */,
        const rpc::mission::IsMissionFinishedRequest* /* request */,
        rpc::mission::IsMissionFinishedResponse* response) override
    {
        auto result_pair = _mission.is_mission_finished();

        if (response != nullptr) {
            fillResponseWithResult(response, result_pair.first);
            response->set_is_finished(result_pair.second);
        }

        return grpc::Status::OK;
    }

    grpc::Status SubscribeMissionProgress(
        grpc::ServerContext* /* context */,
        const mavsdk::rpc::mission::SubscribeMissionProgressRequest* /* request */,
        grpc::ServerWriter<rpc::mission::MissionProgressResponse>* writer) override
    {
        auto stream_closed_promise = std::make_shared<std::promise<void>>();
        auto stream_closed_future = stream_closed_promise->get_future();
        register_stream_stop_promise(stream_closed_promise);

        auto is_finished = std::make_shared<bool>(false);

        std::mutex subscribe_mutex{};

        _mission.mission_progress_async(
            [this, &writer, &stream_closed_promise, is_finished, &subscribe_mutex](
                const mavsdk::Mission::MissionProgress& mission_progress) {
                rpc::mission::MissionProgressResponse rpc_response;

                rpc_response.set_allocated_mission_progress(
                    translateToRpcMissionProgress(mission_progress).release());

                std::lock_guard<std::mutex> lock(subscribe_mutex);
                if (!*is_finished && !writer->Write(rpc_response)) {
                    _mission.mission_progress_async(nullptr);
                    *is_finished = true;
                    unregister_stream_stop_promise(stream_closed_promise);
                    stream_closed_promise->set_value();
                }
            });

        stream_closed_future.wait();
        return grpc::Status::OK;
    }

    grpc::Status GetReturnToLaunchAfterMission(
        grpc::ServerContext* /* context */,
        const rpc::mission::GetReturnToLaunchAfterMissionRequest* /* request */,
        rpc::mission::GetReturnToLaunchAfterMissionResponse* response) override
    {
        auto result_pair = _mission.get_return_to_launch_after_mission();

        if (response != nullptr) {
            fillResponseWithResult(response, result_pair.first);
            response->set_enable(result_pair.second);
        }

        return grpc::Status::OK;
    }

    grpc::Status SetReturnToLaunchAfterMission(
        grpc::ServerContext* /* context */,
        const rpc::mission::SetReturnToLaunchAfterMissionRequest* request,
        rpc::mission::SetReturnToLaunchAfterMissionResponse* response) override
    {
        if (request == nullptr) {
            LogWarn() << "SetReturnToLaunchAfterMission sent with a null request! Ignoring...";
            return grpc::Status::OK;
        }

        auto result = _mission.set_return_to_launch_after_mission(request->enable());

        if (response != nullptr) {
            fillResponseWithResult(response, result);
        }

        return grpc::Status::OK;
    }

    grpc::Status ImportQgroundcontrolMission(
        grpc::ServerContext* /* context */,
        const rpc::mission::ImportQgroundcontrolMissionRequest* request,
        rpc::mission::ImportQgroundcontrolMissionResponse* response) override
    {
        if (request == nullptr) {
            LogWarn() << "ImportQgroundcontrolMission sent with a null request! Ignoring...";
            return grpc::Status::OK;
        }

        auto result_pair = _mission.import_qgroundcontrol_mission(request->qgc_plan_path());

        if (response != nullptr) {
            fillResponseWithResult(response, result_pair.first);
            response->set_allocated_mission_plan(
                translateToRpcMissionPlan(result_pair.second).release());
        }

        return grpc::Status::OK;
    }

    void stop()
    {
        _stopped.store(true);
        for (auto& prom : _stream_stop_promises) {
            if (auto handle = prom.lock()) {
                handle->set_value();
            }
        }
    }

private:
    void register_stream_stop_promise(std::weak_ptr<std::promise<void>> prom)
    {
        // If we have already stopped, set promise immediately and don't add it to list.
        if (_stopped.load()) {
            if (auto handle = prom.lock()) {
                handle->set_value();
            }
        } else {
            _stream_stop_promises.push_back(prom);
        }
    }

    void unregister_stream_stop_promise(std::shared_ptr<std::promise<void>> prom)
    {
        for (auto it = _stream_stop_promises.begin(); it != _stream_stop_promises.end();
             /* ++it */) {
            if (it->lock() == prom) {
                it = _stream_stop_promises.erase(it);
            } else {
                ++it;
            }
        }
    }

    Mission& _mission;
    std::atomic<bool> _stopped{false};
    std::vector<std::weak_ptr<std::promise<void>>> _stream_stop_promises{};
};

} // namespace backend
} // namespace mavsdk