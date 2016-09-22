// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "ICallback.h"
#include "CallbackCollection.h"
#include "VRDistortionMaterial.h"
#include "IVRDistortionTransitionModel.h"

namespace Eegeo
{
    namespace VR
    {
        namespace Distortion
        {
            class VRDistortionTransitionModel : public IVRDistortionTransitionModel, private Eegeo::NonCopyable
            {
            public:
                VRDistortionTransitionModel();

                void SetVisibilityParam(float param);
                float GetVisibilityParam() const { return m_visibilityParam; }

                void RegisterVisibilityChangedCallback(Helpers::ICallback0& callback);
                void UnregisterVisibilityChangedCallback(Helpers::ICallback0& callback);

            private:

                void NotifyStateChange();

                Helpers::CallbackCollection0 m_stateChangedCallbacks;

                float m_visibilityParam;
            };
        }
    }
}