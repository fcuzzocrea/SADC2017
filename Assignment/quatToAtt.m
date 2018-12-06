function A = quatToAtt( quat )
%   Converts a quaternion vector to the attitude matrix A
%
%   A = quatToAtt( quat )
%
%   The quaternion must be written as a 4-by-1 vector with the scalar
%   element as the fourth component.
%   The returned attitude matrix A represents the rotational matrix from 
%   the inertial reference frame to the body frame of the vehicle.
%
%   References:
%	[1] Markley, F. Landis. "Attitude error representations for Kalman filtering." 
%       Journal of guidance control and dynamics 26.2 (2003): 311-317.

quat = quat / norm(quat);

qv = [quat(1) ;
      quat(2) ;
      quat(3)];
qs = quat(4);

rox = [   0    -qv(3)  qv(2) ;
         qv(3)   0    -qv(1) ;
        -qv(2)  qv(1)   0   ];

norm_qv_sq = qv(1)^2 + qv(2)^2 + qv(3)^2;

A = (qs^2 - norm_qv_sq) * eye(3) + 2 * (qv * qv') - 2 * qs * rox;

end