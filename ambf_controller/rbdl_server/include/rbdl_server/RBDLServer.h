#ifndef AMBFRBDLServer_H
#define AMBFRBDLServer_H


#include <ros/ros.h>
#include "rbdl_server/RBDLForwardDynamics.h"
#include "rbdl_server/RBDLInverseDynamics.h"
#include "rbdl_server/RBDLJacobian.h"
#include "rbdl_server/RBDLModel.h"
#include "rbdl_server/RBDLKinimatics.h"
#include "rbdl_server/RBDLBodyNames.h"
#include <geometry_msgs/PoseArray.h>
#include <geometry_msgs/Pose.h>
#include <geometry_msgs/Point.h>
#include <std_msgs/Float64MultiArray.h>
#include <rbdl/rbdl.h>
#include <eigen_conversions/eigen_msg.h>

using namespace RigidBodyDynamics;
using namespace RigidBodyDynamics::Math;

class RBDLServer
{
	private:
                ros::NodeHandle nh_;
                RigidBodyDynamics::Model *model = NULL;
                bool have_model;
                std::map<std::string, int> body_ids; //body ids
                ros::ServiceServer FD_srv, ID_srv, MD_srv, Jac_srv, Kin_srv;
                VectorNd VectToEigen(const std::vector<double>&);
                bool CreateModel_srv(rbdl_server::RBDLModelRequest&, rbdl_server::RBDLModelResponse& ); //parses the AMBF model into  rbdl model
                bool CheckSize(int); //need to implement this to find way of checking the msg field sizes
                bool ForwardDynamics_srv(rbdl_server::RBDLForwardDynamicsRequest&, rbdl_server::RBDLForwardDynamicsResponse&  );
                bool InverseDynamics_srv(rbdl_server::RBDLInverseDynamicsRequest&, rbdl_server::RBDLInverseDynamicsResponse&  );
                bool ForwardKinimatics_srv(rbdl_server::RBDLKinimaticsRequest&, rbdl_server::RBDLKinimaticsResponse&);
                bool Jacobian_srv(rbdl_server::RBDLJacobianRequest&, rbdl_server::RBDLJacobianResponse&);
                bool GetNames_srv(rbdl_server::RBDLBodyNamesRequest&, rbdl_server::RBDLBodyNamesResponse&);
                void GetNames(std::vector<std::string>&);
	
        public:
                RBDLServer(ros::NodeHandle* nodehandle);
                RBDLServer();
                ~RBDLServer();


};

#endif
