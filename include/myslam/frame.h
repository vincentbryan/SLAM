class Frame{
	public:
		typedef std::share_ptr<Frame> Ptr;
		unsigned long id_;
		double time_stamp_;
		SE3 T_c_w_;
		Camera::Ptr camera_;
		Mat color_, depth_;

	public:
		Frame();
		Frame( long id, double time_stamp = 0, SE3 T_c_w = SE3(), Camera::Ptr camera = nullptr, 
			   Mat color  = Mat(), depth = Mat() );
		~Frame();

		//factory pattern
		static Frame::Ptr createFrame();

		//find the depth in depth map
		double findDepth( const cv::KeyPoint& kp );

		//get Camera center
		Vector3d getCameraCenter() const;

		//check if a point is in this frame
		bool isInframe( const Vector3d& pt_world);
};